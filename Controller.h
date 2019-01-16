//
// Created by eyal & tomer on 1/16/19.
//

#ifndef CLIENTSERVER_CONTROLLER_H
#define CLIENTSERVER_CONTROLLER_H
#include "Servers/MySerialServer.h"
#include "Servers/MyParallelServer.h"
#include "CacheManagers/FileCacheManager.h"
#include "Solvers/SearchSolver.h"
#include "ClientHandlers/MyClientHandler.h"
#include "Algorithms/BreadthFirstSearch.h"
#include "Algorithms/DepthFirstSearch.h"
#include "Algorithms/BestFirstSearch.h"
#include "Algorithms/AStar.h"

class Controller {
public:
    void runProgram(int port);
};


#endif //CLIENTSERVER_CONTROLLER_H
