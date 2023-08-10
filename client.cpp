#include <iostream>
#include <boost/asio.hpp>

using IO_Context = boost::asio::io_context;
using Endpoint = boost::asio::ip::tcp::endpoint;
using Socket = boost::asio::ip::tcp::socket;
using Resolver = boost::asio::ip::tcp::resolver;

int main()
{
    try {
        IO_Context ioc;

        // Resolve server address and port number
        Resolver resolver(ioc);
        Resolver::results_type endpoints = resolver.resolve("127.0.0.1", "8080");

        // Create and connect to tcp socket
        Socket socket(ioc);
        boost::asio::connect(socket, endpoints);

        std::cout << "Connected to the server! \n";

        // Send a message to the server
        const std::string message = "Hello, Server!";
        boost::asio::write(socket, boost::asio::buffer(message));

        // Receive the message back
        char data[1024];
        size_t length = socket.read_some(boost::asio::buffer(data));
        std::cout << "Received from server: " << std::string(data, length) << std::endl;

        ioc.run();
    } catch (std::exception& e)
    {
        std::cerr << "Exception " << e.what() <<std::endl;
    }

    return 0;
}