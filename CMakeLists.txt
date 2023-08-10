cmake_minimum_required(VERSION 3.0.0)

if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conaninfo.txt)
    list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}")
endif()

project(boost-asio)

find_package(Boost 1.78 REQUIRED COMPONENTS system)

# Server
add_executable(server server.cpp)

target_link_libraries(server
                      PUBLIC
                      Boost::Boost)

# Client
add_executable(client client.cpp)

target_link_libraries(client
                      PUBLIC
                      Boost::Boost)

