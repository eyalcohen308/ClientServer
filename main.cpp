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

vector<vector<string>> randomMatrix(int row, int col) {
    vector<vector<string>> matrix;
    for (int i = 0; i < row; ++i) {
        vector<string> row_vec;
        for (int j = 0; j < col; ++j) {
            int r = rand() % 5;
            if (r % 6 == 0) r = -1;
            row_vec.push_back(to_string(r));
        }
        matrix.push_back(row_vec);
    }
    matrix[row - 1][col - 1] = to_string(rand() % 10+1);
    matrix.push_back({"0", "0"});
    matrix.push_back({to_string(row - 1), to_string(col - 1)});
    return matrix;
}

void printMatrix(vector<vector<string>> matrix) {
    for (int i = 0; i < matrix.size() - 2; i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] + " ";
        }
        cout << "\n";
    }
}

int main() {

    vector<vector<string>> matrix = randomMatrix(50,50);
    printMatrix(matrix);
    auto *bfs = new BreadthFirstSearch<pair<int, int>>();
    auto *dfs = new DepthFirstSearch<pair<int, int>>();
    auto *astar = new AStar<pair<int, int>>();
    auto *bestfirst = new BestFirstSearch<pair<int, int>>();

    auto *searchSolver1 = new SearchSolver<pair<int, int>, string>(bfs);
    auto *searchSolver2 = new SearchSolver<pair<int, int>, string>(dfs);
    auto *searchSolver3 = new SearchSolver<pair<int, int>, string>(astar);
    auto *searchSolver4 = new SearchSolver<pair<int, int>, string>(bestfirst);

    string res1 = searchSolver1->solve(matrix);
    string res2 = searchSolver2->solve(matrix);
    string res3 = searchSolver3->solve(matrix);
    string res4 = searchSolver4->solve(matrix);

    cout << "bfs:\n" << res1 << endl;
    cout << bfs->getNumOfNodesEvaluated() << endl;
    cout << "dfs:\n" << res2 << endl;
    cout << dfs->getNumOfNodesEvaluated() << endl;
    cout << "Astar:\n" << res3 << endl;
    cout << astar->getNumOfNodesEvaluated() << endl;
    cout << "best first search:\n" << res4 << endl;
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