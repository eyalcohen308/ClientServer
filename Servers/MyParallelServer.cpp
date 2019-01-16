//
// Created by eyal on 1/13/19.
//

#include "MyParallelServer.h"

#include <cstring>
#include <vector>


/**
 * the thread that handle the client
 * @param arg
 * @return
 */
void* handleClient(void* arg){
    //auto args = static_cast<ParamsToUpdate*>(arg);
    struct dataToSoc* params=(struct dataToSoc*) arg;
    params->ch->handleClient(params->sockClient);
}


/**
 * open the threads for the clients
 * @param arg
 * @return
 */
void* acceptClients(void* arg)
{
    //
    vector<dataToSoc*> cli;
    vector<pthread_t> forJoin;
    //


    struct dataToSoc* params=(struct dataToSoc*) arg;

    char *hello = "Hello from server";
    char buffer[256];
    int  n;
    sockaddr_in client_sock;
    int clientSocketVal;
    int clilen = sizeof(client_sock);


    struct dataToSoc *para = new dataToSoc;
    para->ch = params->ch;
    para->sockServer = params->sockServer;
    para->port = params->port;
    para->sockClient = params->sockClient;
    para->shouldStop = params->shouldStop;
    //
    cli.push_back(para);
    //

    // for the first clien- wait unlimited time t
    clientSocketVal = ::accept(para->sockServer, (struct sockaddr *) &client_sock, (socklen_t *) &clilen);
    para->sockClient = clientSocketVal;
    //push to list to free later


    if (para->sockClient < 0) {
        throw invalid_argument("connection with client failed");
    }
    pthread_t threadId;
    pthread_create(&threadId, nullptr, &handleClient, para);
    forJoin.push_back(threadId);
    //now is limited time
    while (!*(params->shouldStop)){


        int new_sock;

        timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;


        setsockopt(params->sockServer, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        clientSocketVal = ::accept(params->sockServer, (struct sockaddr *) &client_sock, (socklen_t *) &clilen);
        if (clientSocketVal < 0)	{
            if (errno == EWOULDBLOCK)	{


                break;
            }	else	{
                perror("other error");
                return nullptr;
            }
        }else{

            params->sockClient = clientSocketVal;
            if (params->sockClient < 0) {
                throw invalid_argument("connection with client failed");
            }


            pthread_t threadId;

            struct dataToSoc *para = new dataToSoc;
            para->ch = params->ch;
            para->sockServer = params->sockServer;
            para->port = params->port;
            para->sockClient = params->sockClient;
            para->shouldStop = params->shouldStop;
            //
            cli.push_back(para);
            //

            pthread_create(&threadId, nullptr, &handleClient, params);

            timeout.tv_sec = 0;
            setsockopt(params->sockClient, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
            //
            forJoin.push_back(threadId);
            //
        }

    }



    for (int i =0;i<forJoin.size();++i){
        pthread_join(forJoin[i], nullptr);

    }
    //  pthread_mutex_unlock(&args->getMutex());

    for (int i =0;i<cli.size();++i){
        delete(cli[i]);
    }
    return nullptr;
}

/**
 * initilize some parameters from the struct and call to the function that create the socket
 * @param port
 * @param clientHandler
 * @return
 */
void MyParallelServer:: open(int port, ClientHandler* clientHandler){
    //ParamsToUpdate* paramsToUpdate = new  ParamsToUpdate();
    //paramsToUpdate->setPortServer(port);
    struct dataToSoc *params = new dataToSoc;
    params->port = port;
    params->shouldStop = &(this->shouldStop);
    params->ch = clientHandler;
    //calls the function opens the socket
    //paramsToUpdate->setClient(clientHandler);
    start(params);
    delete(params);
}


/**
 * create the socket
 * @param params
 */
void MyParallelServer:: start(dataToSoc* params){
    //Create a socket point
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverSocket == -1) {
        throw invalid_argument("Error opening socket");
    }

    params->sockServer=serverSocket;
    //paramsToUpdate->defineSocketServer(serverSocket);
    // Define the client socket's structures
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(params->port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(serverSocket, SOMAXCONN) < 0)   {
        perror("listen error");
        exit(1);
    }
    pthread_create(&thread, nullptr, &acceptClients, params);

    pthread_join(thread, nullptr);
}

/**
 * finish with the Socket
 */
void MyParallelServer:: stop(){
    pthread_cancel(thread);
    close(this->serverSocket);
}