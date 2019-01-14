cmake_minimum_required(VERSION 3.13)
project(ClientServer)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(ClientServer main.cpp Servers/Server.h Servers/MySerialServer.cpp
Servers/MySerialServer.h ClientHandlers/ClientHandler.h
ClientHandlers/MyTestClientHandler.cpp ClientHandlers/MyTestClientHandler.h
Solvers/StringReverser.cpp Solvers/StringReverser.h CacheManagers/CacheManager.h
CacheManagers/FileCacheManager.cpp CacheManagers/FileCacheManager.h
searchAlgo/Searchable.h searchAlgo/Searcher.h searchAlgo/State.cpp searchAlgo/State.h

        Algorithms/BestFirstSearch.cpp Algorithms/BestFirstSearch.h Servers/MyParallelServer.cpp Servers/MyParallelServer.h

ClientHandlers/MyClientHandler.cpp ClientHandlers/MyClientHandler.h Matrix/Matrix.cpp Matrix/Matrix.h Matrix/MatrixResult.cpp Matrix/MatrixResult.h Solvers/SearchSolver.cpp Solvers/SearchSolver.h Algorithms/BreadthFirstSearch.cpp Algorithms/BreadthFirstSearch.h Algorithms/DepthFirstSearch.cpp Algorithms/DepthFirstSearch.h Algorithms/AStar.cpp Algorithms/AStar.h)

