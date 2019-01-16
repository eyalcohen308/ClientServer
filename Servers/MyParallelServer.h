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
using namespace server_side;

struct dataToSoc{
    int port;
    int sockServer;
    int sockClient;
    ClientHandler* ch;
    bool * shouldStop;
};

class MyParallelServer :public Server{
private:
    pthread_t thread;
    int clientSock;
    int serverSocket;
    bool shouldStop;

public:
    MyParallelServer(){
        this->shouldStop = false;
    }
    virtual void open(int port, ClientHandler* clientHandler);
    virtual void stop();
    void start(dataToSoc* param);
    void setStop(){
        this->shouldStop = true;
    }
};

#endif //CLIENTSERVER_MYPARALLELSERVER_H
