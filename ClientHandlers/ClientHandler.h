//
// Created by tomer on 1/3/19.
//

#ifndef CLIENTSERVER_CLIENTHANDLER_H
#define CLIENTSERVER_CLIENTHANDLER_H
#include <iostream>
using namespace std;

class ClientHandler {
public:
    ClientHandler() {}; // // ctor- empty for now
    virtual void handleClient(istream input_stream, ostream output_stream);
};


#endif //CLIENTSERVER_CLIENTHANDLER_H
