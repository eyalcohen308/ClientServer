//
// Created by eyal on 1/13/19.
//

#include "MyParallelServer.h"

void *handleClient(void *arg) {
    struct SocketData *params = (struct SocketData *) arg;

    params->ch->handleClient(params->sockClient);
}


void *acceptClients(void *arg) {
    struct SocketData *params = (struct SocketData *) arg;

    sockaddr_in client_sock;
    int clientSocketVal;
    int clilen = sizeof(client_sock);

    while (!*(params->shouldStop)) {

        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(params->sockServer, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        clientSocketVal = ::accept(params->sockServer, (struct sockaddr *) &client_sock, (socklen_t *) &clilen);
        if (clientSocketVal < 0) {
            if (*(params->shouldStop)) break;
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                continue;
            } else {
                perror("whatttt error");
                exit(1);
            }
        } else {

            params->sockClient = clientSocketVal;
            if (params->sockClient < 0) {
                throw invalid_argument("connection with client failed");
            }
            pthread_t threadId;
            pthread_create(&threadId, nullptr, &handleClient, params);
        }

    }
    return nullptr;
}


void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    struct SocketData *params = new SocketData;
    params->port = port;
    params->shouldStop = &(stoped);
    params->ch = clientHandler;
    start(params);
}


void MyParallelServer::start(SocketData *params) {
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverSocket == -1) {
        throw invalid_argument("Error opening socket");
    }

    params->sockServer = serverSocket;
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(params->port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }
    //TODO שיננו את המקסימומי
    if (listen(serverSocket, MAX_CONNECTED_CLIENTS) < 0) {
        perror("listen error");
        exit(1);
    }
    pthread_create(&thread, nullptr, &acceptClients, params);

    pthread_join(thread, nullptr);
    cout << "finished handle clients" << endl;
}


void MyParallelServer::stop() {
    pthread_cancel(thread);
    close(this->serverSocket);
    cout << "Server stopped" << endl;

}