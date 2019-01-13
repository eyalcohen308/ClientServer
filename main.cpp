#include <iostream>
#include "Solvers/Solver.h"
#include "Solvers/StringReverser.h"
#include "CacheManagers/CacheManager.h"
#include "CacheManagers/FileCacheManager.h"

int main() {
    Solver<string, string> *solver = new StringReverser();
    string name = "ronen";
    string solution = solver->solve(name);
    CacheManager<string, string> *c = new FileCacheManager<string, string>();
    c->saveSolutionFor(name, solution);
    if (c->hasSolutionTo(name)) {
        cout << *(c->getSolutionTo(name)) << endl;
    }
    delete (solver);
    delete (c);
}