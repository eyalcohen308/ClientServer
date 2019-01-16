//
// Created by eyal & tomer on 1/13/19.
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

struct Socket_Data{
    int port;
    int server_socket;
    int client_socket;
    ClientHandler* client_handler;
    bool * need_to_stop;
};

class MyParallelServer :public Server{
private:
    pthread_t thread;
    int server_p_socket;
    bool need_to_p_stop;

public:
    /**
     * Ctor - should'nt stop
     */
    MyParallelServer(){
        this->need_to_p_stop = false;
    }
    virtual void open(int port, ClientHandler* clientHandler);
    virtual void stop();
    void start(Socket_Data* param);
    void setStop(){
        this->need_to_p_stop = true;
    }
};

#endif //CLIENTSERVER_MYPARALLELSERVER_H
