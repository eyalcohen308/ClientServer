cmake_minimum_required(VERSION 3.13)
project(ClientServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientServer main.cpp Servers/Server.h Servers/MySerialServer.cpp
Servers/MySerialServer.h ClientHandlers/ClientHandler.h
ClientHandlers/MyTestClientHandler.cpp ClientHandlers/MyTestClientHandler.h
Solvers/StringReverser.cpp Solvers/StringReverser.h CacheManagers/CacheManager.h
CacheManagers/FileCacheManager.cpp CacheManagers/FileCacheManager.h
searchAlgo/Searchable.h searchAlgo/Searcher.h searchAlgo/State.cpp searchAlgo/State.h
searchAlgo/BestFirstSearch.cpp searchAlgo/BestFirstSearch.h ClientHandlers/MyClientHandler.cpp ClientHandlers/MyClientHandler.h)
