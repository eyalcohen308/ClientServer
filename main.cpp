// Tomer Shlasky 204300602
//
//#include <vector>
//#include "Solvers/Solver.h"
//#include "Solvers/StringReverser.h"
//#include "CacheManagers/CacheManager.h"
//#include "CacheManagers/FileCacheManager.h"
//#include "Solvers/SearchSolver.h"
//#include "Algorithms/BreadthFirstSearch.h"
//#include "Algorithms/DepthFirstSearch.h"
//#include <string>
//
//using namespace std;
//
//int main() {
//
//    vector<vector<string>> ff;
//    vector<string> dd = {"1", "2", "3"};
//    ff.push_back(dd);
//    vector<string> gg = {"1", "-1", "1"};
//    ff.push_back(gg);
//    vector<string> ww = {"7", "4", "9"};
//    ff.push_back(ww);
//    vector<string> w = {"0", "0"};
//    ff.push_back(w);
//    vector<string> w0 = {"2", "0"};
//    ff.push_back(w0);
//
////    auto *bfs = new BreadthFirstSearch<pair<int, int>>();
//    auto *dfs = new DepthFirstSearch<pair<int, int>>();
//
//    auto *searchSolver = new SearchSolver<pair<int, int>, string>(dfs);
//    string res = searchSolver->solve(ff);
//    cout << res << endl;

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

#include <iostream>
#
#include <iostream>
#include <chrono>
#include "Servers/MyParallelServer.h"
#include "Servers/MySerialServer.h"
#include "CacheManagers/FileCacheManager.h"
#include "ClientHandlers/MyClientHandler.h"
#include "Algorithms/BreadthFirstSearch.h"
#include "Solvers/SearchSolver.h"
#include "Algorithms/DepthFirstSearch.h"

int main() {
    //  ParamsToUpdate* params = new ParamsToUpdate();
    // auto start = std::chrono::system_clock::now();
    //Searcher<int>* solver = new BestFirstSearch<int>();
    auto* mySerialServer = new MySerialServer();
/*
   auto* ooo = new SocketRead(5402);ParallelServer
   auto* bbb = new SocketWriter(5400);
*/

    //RowAndCol fff()
    // Searcher<> best = new BestFirstSearch
    // auto* best = new BestFirstSearch<RowAndCol>();
    auto* mm = new FileCacheManager<string,string>;
    //mm->loadFile();
    auto* nn = new DepthFirstSearch<pair<int,int>>();
    auto* serchhhhh = new SearchSolver<pair<int,int>, string>(nn);
    //auto* paramsToUpdate = new ParamsToUpdate();
    auto* clietS = new MyClientHandler(serchhhhh, mm);


    mySerialServer->open(5400,clietS);

    delete (mm);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}