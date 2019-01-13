//
// Created by tomer on 1/3/19.
//

#ifndef CLIENTSERVER_SERVER_H
#define CLIENTSERVER_SERVER_H

#include "../ClientHandlers/ClientHandler.h"

namespace server_side {
    class Server {
    public:
//        Server() {}; // ctor- empty for now
        virtual void open(int port, ClientHandler *c)=0;
// getting port to listen, open the server and wait for clients
        virtual void stop() = 0; // close the server
    };
}
#endif //CLIENTSERVER_SERVER_H
