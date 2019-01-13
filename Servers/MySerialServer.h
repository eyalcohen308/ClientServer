//
// Created by tomer on 1/3/19.
//

#ifndef CLIENTSERVER_MYSERIALSERVER_H
#define CLIENTSERVER_MYSERIALSERVER_H

#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <strings.h>

class MySerialServer : server_side::Server {
private:
    int sock_fd, client_sock_fd;
    struct sockaddr_in m_socket;
    bool should_stop;
public:
    MySerialServer(int sock_fd) : sock_fd(sock_fd) {
        should_stop = false;
    }

    virtual void open(int port, ClientHandler *c);

    virtual void stop();
};


#endif //CLIENTSERVER_MYSERIALSERVER_H
