//
// Created by eyal & tomer on 1/16/19.
//

#ifndef CLIENTSERVER_CONTROLLER_H
#define CLIENTSERVER_CONTROLLER_H
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "FileCacheManager.h"
#include "SearchSolver.h"
#include "MyClientHandler.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "BestFirstSearch.h"
#include "AStar.h"

class Controller {
public:
    void runProgram(int port);
};


#endif //CLIENTSERVER_CONTROLLER_H
