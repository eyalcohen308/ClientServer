//
// Created by eyal on 1/13/19.
//

#ifndef CLIENTSERVER_MYPARALLELSERVER_H
#define CLIENTSERVER_MYPARALLELSERVER_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <pthread.h>

#include "Server.h"

#define MAX_CONNECTED_CLIENTS 1
using namespace server_side;

struct SocketData {
    int port;
    int sockServer;
    int sockClient;
    ClientHandler *ch;
    bool *shouldStop;
};
class MyParallelServer : public Server {
    pthread_t thread;
    int clientSock;
    int serverSocket;
    bool stoped;
public:
    MyParallelServer() {
        this->stoped = false;
    }

    virtual void open(int port, ClientHandler *clientHandler);

    virtual void stop();

    void start(SocketData *param);

    void setStop() {
        this->stoped = true;
    }

};

#endif //CLIENTSERVER_MYPARALLELSERVER_H
