# TCP Echo Server and Client using Boost ASIO

## Overview
This repository contains a simple TCP echo server and client implemented using Boost ASIO in C++. The server accepts connections from clients and echoes back any data it receives. The client connects to the server, sends a message, and receives the echoed data.

## Prerequisites
- C++ Compiler supporting C++11 or later
- [Boost Library](https://www.boost.org/users/download/)
- CMake (for building the project)
- Conan (for package management)

## How to Build
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Nauroze/boost-asio.git
2. **Navigate to the Project Directory:**
    ```bash
    cd boost-asio
3. **Create a Build Directory:**
   ```bash
   mkdir build && cd build
4. **Configure with CMake:**
   ```bash
   cmake ..
5. **Compile the Server and Client:**
   ```bash
   make
## Usage
1. **Run the Server:**
   ```bash
   ./server
2. **Run the Client:**
   ```bash
   ./client
## Project Structure
- server.cpp: Contains the code for the TCP echo server.
- client.cpp: Contains the code for the TCP client.
- CMakeLists.txt: CMake configuration file for building the project.
- conanfile.py: Conan configuration file for managing dependencies.
## Features
- TCP Connection Handling: Establishes a TCP connection between the client and server.
- Data Transmission: Sends, receives, and echoes data between the client and server.
- Scalable Foundation: Serves as a starting point for more complex networking applications, including asynchronous functions, multi-threading, and robust error handling.
