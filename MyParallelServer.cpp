//
// Created by eyal & tomer on 1/13/19.
//

#include "MyParallelServer.h"

#include <cstring>
#include <vector>


/**
 * handle the client
 * @param arg
 * @return
 */
void *handleClient(void *arg) {
    struct Socket_Data *params = (struct Socket_Data *) arg;
    params->client_handler->handleClient(params->client_socket);
}


/**
 * open threads for the clients
 * @param arg
 * @return
 */
void *acceptClients(void *arg) {
    vector<Socket_Data *> clients_vec; // vector for clients
    vector<pthread_t> threads_vec; // to do the join

    struct Socket_Data *params = (struct Socket_Data *) arg;

    sockaddr_in client_sock;
    int sock_client_val;
    int client_s = sizeof(client_sock);

    // init params
    struct Socket_Data *para = new Socket_Data;
    para->client_handler = params->client_handler;
    para->server_socket = params->server_socket;
    para->port = params->port;
    para->client_socket = params->client_socket;
    para->need_to_stop = params->need_to_stop;
    // insert params to vector
    clients_vec.push_back(para);

    /**
     * for the first client- wait unlimited time t
     */
    sock_client_val = ::accept(para->server_socket, (struct sockaddr *) &client_sock, (socklen_t *) &client_s);
    para->client_socket = sock_client_val;

    if (para->client_socket < 0) {
        throw invalid_argument("connection with client failed");
    }
    pthread_t thread_id;
    pthread_create(&thread_id, nullptr, &handleClient, para);
    threads_vec.push_back(thread_id);

    /**
     * now, for every client- limited time
     */
    while (!*(params->need_to_stop)) {
        // set timeval
        timeval time_out;
        time_out.tv_sec = 1;
        time_out.tv_usec = 0;

        setsockopt(params->server_socket, SOL_SOCKET, SO_RCVTIMEO, (char *) &time_out, sizeof(time_out));

        sock_client_val = ::accept(params->server_socket, (struct sockaddr *) &client_sock, (socklen_t *) &client_s);
        if (sock_client_val < 0) {
            if (errno == EWOULDBLOCK) {
                break;
            } else {
                perror("Error in socket");
                return nullptr;
            }
        } else {
            params->client_socket = sock_client_val;
            if (params->client_socket < 0) {
                throw invalid_argument("connection with client failed");
            }
            pthread_t id_thread;
            // init struct
            struct Socket_Data *para = new Socket_Data;
            para->client_handler = params->client_handler;
            para->server_socket = params->server_socket;
            para->port = params->port;
            para->client_socket = params->client_socket;
            para->need_to_stop = params->need_to_stop;
            // insert params to vector
            clients_vec.push_back(para);

            pthread_create(&id_thread, nullptr, &handleClient, params);

            time_out.tv_sec = 0;
            setsockopt(params->client_socket, SOL_SOCKET, SO_RCVTIMEO, (char *) &time_out, sizeof(time_out));
            // insert to thread vec
            threads_vec.push_back(id_thread);
        }

    }

    /**
     * wait for all threads to finish
     */
    for (int i = 0; i < threads_vec.size(); ++i) {
        pthread_join(threads_vec[i], nullptr);

    }

    /**
     * delete all structs
     */
    for (int i = 0; i < clients_vec.size(); ++i) {
        delete (clients_vec[i]);
    }

    return nullptr; // finish
}

/**
 * initilize parameters from the struct
 * call to function for creating a socket
 * @param port
 * @param clientHandler
 * @return
 */
void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    // init struct
    struct Socket_Data *params = new Socket_Data;
    params->port = port;
    params->need_to_stop = &(this->need_to_p_stop);
    params->client_handler = clientHandler;
    start(params); //calls the function opens the socket
    delete (params); // free
}

/**
 * create the socket
 * @param params
 */
void MyParallelServer::start(Socket_Data *params) {
    // create socket
    this->server_p_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_p_socket == -1) {
        throw invalid_argument("Error opening socket");
    }

    // Define the client socket's structures
    params->server_socket = server_p_socket;
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(params->port);
    if (bind(server_p_socket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(server_p_socket, SOMAXCONN) < 0) {
        perror("listen error");
        exit(1);
    }
    // if no error - call to thread and accept clients
    pthread_create(&thread, nullptr, &acceptClients, params);
    // join
    pthread_join(thread, nullptr);
}

/**
 * stop all threads
 */
void MyParallelServer::stop() {
    pthread_cancel(thread);
    close(this->server_p_socket);
}

