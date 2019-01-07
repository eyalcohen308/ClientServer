//
// Created by tomer on 1/3/19.
//

#ifndef CLIENTSERVER_MYSERIALSERVER_H
#define CLIENTSERVER_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : server_side::Server {
private:
    int sock_fd, client_sock_fd;
    bool stop;
public:
    virtual void open(int port, ClientHandler c);
    virtual void stop();
};


#endif //CLIENTSERVER_MYSERIALSERVER_H
