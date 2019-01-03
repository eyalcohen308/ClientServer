cmake_minimum_required(VERSION 3.13)
project(ClientServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientServer main.cpp Servers/Server.h Servers/MySerialServer.cpp Servers/MySerialServer.h ClientHandlers/ClientHandler.h ClientHandlers/MyTestClientHandler.cpp ClientHandlers/MyTestClientHandler.h)