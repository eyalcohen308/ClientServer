// Tomer Shlasky 204300602
//
#include <vector>
#include "Solvers/Solver.h"
#include "Solvers/StringReverser.h"
#include "CacheManagers/CacheManager.h"
#include "CacheManagers/FileCacheManager.h"
#include "Solvers/SearchSolver.h"

#include "EmpiricalExperiment.h"
#include "Servers/MySerialServer.h"
#include "ClientHandlers/MyClientHandler.h"
#include "Controller.h"
#include <string>

int main(int argc, char *argv[]) {
    int port;
    if (argc != 2) {
        throw runtime_error("invalid args!");
    }
    try {
        port = stoi(argv[1]); // try convert to int
    } catch (invalid_argument &ex) {
        throw runtime_error("invalid port!");
    }
    // valid- create controller and run program
    auto *controller = new Controller();
    controller->runProgram(port);
    delete (controller); // free controller
    return 0;
}
