// Tomer Shlasky 204300602
//
#include <vector>
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "SearchSolver.h"

#include "EmpiricalExperiment.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
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
