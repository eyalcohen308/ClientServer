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
#include <string>

using namespace std;

int main() {

    vector<vector<string>> ff;
    vector<string> dd = {"1", "1", "-1","-1", "3", "5","1"};
    ff.push_back(dd);
    vector<string> gg = {"5", "1", "1","1", "1", "1","-1"};
    ff.push_back(gg);
    vector<string> ww = {"1", "7", "2","2", "3", "1","10"};
    ff.push_back(ww);
    vector<string> ss = {"1", "7", "-1","-1", "3", "1","10"};
    ff.push_back(ss);
    vector<string> w = {"0", "0"};
    ff.push_back(w);
    vector<string> w0 = {"0", "6"};
    ff.push_back(w0);

    auto *bfs = new BreadthFirstSearch<pair<int, int>>();
    auto *dfs = new DepthFirstSearch<pair<int, int>>();
    auto *astar = new AStar<pair<int, int>>();
    auto *bestfirst = new BestFirstSearch<pair<int, int>>();

    auto *searchSolver1 = new SearchSolver<pair<int, int>, string>(bfs);
    auto *searchSolver2 = new SearchSolver<pair<int, int>, string>(dfs);
    auto *searchSolver3 = new SearchSolver<pair<int, int>, string>(astar);
    auto *searchSolver4 = new SearchSolver<pair<int, int>, string>(bestfirst);

    string res1 = searchSolver1->solve(ff);
    string res2 = searchSolver2->solve(ff);
    string res3 = searchSolver3->solve(ff);
    string res4 = searchSolver4->solve(ff);

    cout << "bfs:\n" <<res1 << endl;
    cout << bfs->getNumOfNodesEvaluated() << endl;
    cout << "dfs:\n" <<res2 << endl;
    cout << dfs->getNumOfNodesEvaluated() << endl;
    cout << "Astar:\n" <<res3 << endl;
    cout << astar->getNumOfNodesEvaluated() << endl;
    cout << "best first search:\n" <<res4 << endl;
    cout << bestfirst->getNumOfNodesEvaluated() << endl;
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

}
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