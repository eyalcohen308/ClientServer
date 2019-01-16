cmake_minimum_required(VERSION 3.13)
project(ClientServer)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(ClientServer main.cpp Server.h MySerialServer.cpp
        MySerialServer.h ClientHandler.h
        MyTestClientHandler.cpp MyTestClientHandler.h
        StringReverser.cpp StringReverser.h CacheManager.h
        FileCacheManager.cpp FileCacheManager.h
        Searchable.h Searcher.h State.cpp State.h
        BestFirstSearch.cpp BestFirstSearch.h
        MyParallelServer.cpp MyParallelServer.h
        MyClientHandler.cpp MyClientHandler.h
        Matrix.cpp Matrix.h MatrixResult.cpp
        MatrixResult.h SearchSolver.cpp
        SearchSolver.h BreadthFirstSearch.cpp
        BreadthFirstSearch.h DepthFirstSearch.cpp
        DepthFirstSearch.h AStar.cpp
        AStar.h EmpiricalExperiment.cpp
        EmpiricalExperiment.h AbstractAstarBest.cpp
        AbstractAstarBest.h Controller.cpp Controller.h)

