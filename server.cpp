#include <iostream>
#include <boost/asio.hpp>

using IO_Context = boost::asio::io_context;
using Acceptor = boost::asio::ip::tcp::acceptor;
using Endpoint = boost::asio::ip::tcp::endpoint;
using Socket = boost::asio::ip::tcp::socket;
int main()
{
    try {
        IO_Context ioc;
        Endpoint endpoint(boost::asio::ip::tcp::v4(), 8080);
        Acceptor acceptor(ioc, endpoint);

        std::cout << "Server is now running on port 8080 \n";

        // Accept one connection
        Socket socket(ioc);
        acceptor.accept(socket);
        std::cout << "Connection accepted! \n";

        // Read data from client
        char data[1024];
        size_t length = socket.read_some(boost::asio::buffer(data));

        std::cout << "Data from client: " << data;

        // Echo it back
        boost::asio::write(socket, boost::asio::buffer(data, length));
        std::cout << "Data echoed back to client" << std::endl;

        ioc.run();
    } catch (std::exception& e)
    {
        std::cerr << "Exception " << e.what() <<std::endl;
    }

    return 0;
}