//
// Created by tomer on 1/16/19.
//

#include "Controller.h"

void Controller::runProgram(int port) {
//    EmpiricalExperiment empiricalExperiment;
//    empiricalExperiment.testAndWriteToFiles();
    auto * server = new MyParallelServer(); // server
    auto * cm = new FileCacheManager<string,string>(); // inside- load the solution

    auto *searcher = new BestFirstSearch<pair<int, int>>();

    auto *searchSolver = new SearchSolver<pair<int, int>, string>(searcher);
    auto *client = new MyClientHandler(searchSolver, cm);
    server->open(port, client);

    delete(cm); // Dtor write solution
    delete (server);
    delete(searcher);
    delete(searchSolver);
    delete(client);
}
