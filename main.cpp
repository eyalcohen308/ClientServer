// Tomer Shlasky 204300602

#include <vector>
#include "Solvers/Solver.h"
#include "Solvers/StringReverser.h"
#include "CacheManagers/CacheManager.h"
#include "CacheManagers/FileCacheManager.h"
#include "Solvers/SearchSolver.h"
#include "Algorithms/BreadthFirstSearch.h"
#include "Algorithms/DepthFirstSearch.h"
#include <string>

using namespace std;

int main() {

    vector<vector<string>> ff;
    vector<string> dd = {"1", "2", "3"};
    ff.push_back(dd);
    vector<string> gg = {"1", "-1", "1"};
    ff.push_back(gg);
    vector<string> ww = {"7", "4", "9"};
    ff.push_back(ww);
    vector<string> w = {"0", "0"};
    ff.push_back(w);
    vector<string> w0 = {"2", "0"};
    ff.push_back(w0);

//    auto *bfs = new BreadthFirstSearch<pair<int, int>>();
    auto *dfs = new DepthFirstSearch<pair<int, int>>();

    auto *searchSolver = new SearchSolver<pair<int, int>, string>(dfs);
    string res = searchSolver->solve(ff);
    cout << res << endl;

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
