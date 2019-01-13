//
// Created by tomer on 1/3/19.
//

#include "MySerialServer.h"

//struct of data.
struct Socket_Data {
    int port;
    int sock_fd;
    ClientHandler *ch;
    bool *should_stop;
};

int accept(int sock_fd) {
    sockaddr_in client_sock;
    int clilen;
    int client_sock_fd = ::accept(sock_fd, (struct sockaddr *) &client_sock, (socklen_t *) &clilen);
    if (client_sock_fd < 0) {
        __throw_bad_exception();
    }
    return client_sock_fd;

}

void *threadFunction(void *args) {
    ///read
    struct Socket_Data *params = (struct Socket_Data *) args;

    while (!*(params->should_stop)) {
        int id = accept(params->sock_fd);
        params->ch->handleClient(id);
        //TODO time handler
    }

    delete params;
    return nullptr;
}

void *createThread(void *pVoid) {

    struct Socket_Data *params = (struct Socket_Data *) pVoid;
    pthread_t trid;
    pthread_create(&trid, nullptr, threadFunction, params);
    return 0;
}

void MySerialServer::open(int port, ClientHandler *ch) {

    int portno;

    /* First call to m_socket() function */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("failed try to open socket.\n");
        exit(1);
    }


    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));
    portno = port;

    this->m_socket.sin_family = AF_INET;
    this->m_socket.sin_addr.s_addr = INADDR_ANY;
    this->m_socket.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sock_fd, (struct sockaddr *) &this->m_socket, sizeof(this->m_socket)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    //open thread
    listen(sock_fd, 1);
    struct Socket_Data *params = new Socket_Data;
    params->port = port;
    params->sock_fd = this->sock_fd;
    params->should_stop = &(this->should_stop);
    params->ch = ch;
    createThread(params);
    string x;
    cin >> x;

}
