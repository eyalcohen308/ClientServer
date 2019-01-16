// Tomer Shlasky 204300602
//
#include <vector>
#include "Solvers/Solver.h"
#include "Solvers/StringReverser.h"
#include "CacheManagers/CacheManager.h"
#include "CacheManagers/FileCacheManager.h"
#include "Solvers/SearchSolver.h"
#include "Algorithms/BreadthFirstSearch.h"
#include "Algorithms/DepthFirstSearch.h"
#include "Algorithms/BestFirstSearch.h"
#include "Algorithms/AStar.h"
#include "EmpiricalExperiment.h"
#include "Servers/MySerialServer.h"
#include "ClientHandlers/MyClientHandler.h"
#include <string>

int main() {
//    EmpiricalExperiment empiricalExperiment;
//    empiricalExperiment.testAndWriteToFiles();
    auto * serial = new MySerialServer(); // server
    auto * cm = new FileCacheManager<string,string>(); // inside- load the solution

    auto *sercher = new BestFirstSearch<pair<int, int>>();

    auto *searchSolver = new SearchSolver<pair<int, int>, string>(sercher);
    auto *client = new MyClientHandler(searchSolver, cm);
    serial->open(5400, client);
    // waiting for char
    cm->writeSolutions();
//
    delete(cm);
    delete (serial);
    delete(sercher);
    delete(searchSolver);
    delete(client);
    return 0;
}
//
//    Solver<string, string> *solver = new StringReverser();
//    string name = "ronen";
//    string solution = solver->solve(name);
//    CacheManager<string, string> *c = new FileCacheManager<string, string>();
//    c->saveSolutionFor(name, solution);
//    if (c->hasSolutionTo(name)) {
//        cout << (c->getSolutionTo(name)) << endl;
//    }
//    delete (solver);
//    delete (c);

//}
//
//#include <iostream>
//#
//#include <iostream>
//#include <chrono>
//#include "Servers/MyParallelServer.h"
//#include "Servers/MySerialServer.h"
//#include "CacheManagers/FileCacheManager.h"
//#include "ClientHandlers/MyClientHandler.h"
//#include "Algorithms/BreadthFirstSearch.h"
//#include "Solvers/SearchSolver.h"
//#include "Algorithms/DepthFirstSearch.h"
//
//int main() {
//    //  ParamsToUpdate* params = new ParamsToUpdate();
//    // auto start = std::chrono::system_clock::now();
//    //Searcher<int>* solver = new BestFirstSearch<int>();
//    auto* mySerialServer = new MySerialServer();
///*
//   auto* ooo = new SocketRead(5402);ParallelServer
//   auto* bbb = new SocketWriter(5400);
//*/
//
//    //RowAndCol fff()
//    // Searcher<> best = new BestFirstSearch
//    // auto* best = new BestFirstSearch<RowAndCol>();
//    auto* mm = new FileCacheManager<string,string>;
//    //mm->loadFile();
//    auto* nn = new DepthFirstSearch<pair<int,int>>();
//    auto* serchhhhh = new SearchSolver<pair<int,int>, string>(nn);
//    //auto* paramsToUpdate = new ParamsToUpdate();
//    auto* clietS = new MyClientHandler(serchhhhh, mm);
//
//
//    mySerialServer->open(5400,clietS);
//
//    delete (mm);
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}