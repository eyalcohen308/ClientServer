cmake_minimum_required(VERSION 3.13)
project(ClientServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientServer main.cpp Solvers/Solver.h Solvers/StringReverser.cpp Solvers/StringReverser.h CacheManagers/CacheManager.h CacheManagers/FileCacheManager.cpp CacheManagers/FileCacheManager.h)