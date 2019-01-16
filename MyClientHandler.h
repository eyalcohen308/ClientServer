//
// Created by eyal & tomer on 1/13/19.
//

#ifndef CLIENTSERVER_MYCLIENTHANDLER_H
#define CLIENTSERVER_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <vector>
#include <regex>
#include <unistd.h>
#include <string>


#define CHARS_TO_WRITE 10000000000
#define CHARS_TO_BUFFER 100


class MyClientHandler : public ClientHandler {
    // members
    Solver<vector<vector<string>>, string> *solver;
    CacheManager<string, string> *cache_Manager;

    void writeSolutionToSocket(string sol, int sock_id);

    string getLineFromSocket(int sock_id);

public:
    MyClientHandler(Solver<vector<vector<string>>, string> *solver,
                    CacheManager<string, string> *cache_Manager)
            : solver(solver), cache_Manager(cache_Manager) {};

    string getData(int sock_id);

    virtual void handleClient(int sock_id);

    vector<vector<string>> lexer(string input);
};


#endif //CLIENTSERVER_MYCLIENTHANDLER_H
