//
// Created by eyal & tomer on 1/3/19.
//

#ifndef CLIENTSERVER_CLIENTHANDLER_H
#define CLIENTSERVER_CLIENTHANDLER_H

#include <iostream>

using namespace std;

class ClientHandler {
public:
    ClientHandler() {}; // // ctor- empty for now
    virtual void handleClient(int id) = 0;
};


#endif //CLIENTSERVER_CLIENTHANDLER_H
