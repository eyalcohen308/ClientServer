//
// Created by eyal & tomer on 1/3/19.
//

#ifndef CLIENTSERVER_MYTESTCLIENTHANDLER_H
#define CLIENTSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "../Solvers/Solver.h"
#include "../CacheManagers/CacheManager.h"

class MyTestClientHandler : ClientHandler {
    Solver<string,string> *solver;
    CacheManager<string,string> *cm;
public:
    virtual void handleClient(istream input_stream, ostream output_stream);

};


#endif //CLIENTSERVER_MYTESTCLIENTHANDLER_H
