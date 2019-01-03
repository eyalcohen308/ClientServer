//
// Created by tomer on 1/3/19.
//

#ifndef CLIENTSERVER_MYTESTCLIENTHANDLER_H
#define CLIENTSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"

class MyTestClientHandler : ClientHandler {
    Solver solver;
    CacheManager cm;
public:
    virtual void handleClient(istream input_stream, ostream output_stream);

};


#endif //CLIENTSERVER_MYTESTCLIENTHANDLER_H
