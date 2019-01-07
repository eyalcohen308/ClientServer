cmake_minimum_required(VERSION 3.13)
project(ClientServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientServer main.cpp searchAlgo/Searchable.h searchAlgo/Searcher.h searchAlgo/State.cpp searchAlgo/State.h searchAlgo/BestFirstSearch.cpp searchAlgo/BestFirstSearch.h)