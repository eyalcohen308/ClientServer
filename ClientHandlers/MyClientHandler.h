//
// Created by tomer on 1/13/19.
//

#ifndef CLIENTSERVER_MYCLIENTHANDLER_H
#define CLIENTSERVER_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "../Solvers/Solver.h"
#include "../CacheManagers/CacheManager.h"
#include <vector>


class MyClientHandler : public ClientHandler {
    // members
    Solver<vector<vector<string>>, string> *solver;
    CacheManager<string, string> *cache_Manager;

public:
    MyClientHandler(Solver<vector<vector<string>>, string> *solver,
                    CacheManager<string, string> *cache_Manager)
            : solver(solver),
              cache_Manager(cache_Manager) {};
    string
};


#endif //CLIENTSERVER_MYCLIENTHANDLER_H
