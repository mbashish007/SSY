/*
============================================================================
Name: 34b.c 

Author: M B Ashish

Roll No: MT2024085

Description: 34. Write a program to create a concurrent server.
                a. use fork
                b. use pthread_create

Date: 21 September, 2024.
============================================================================

Output
Server listening on port 6041...
Client connected!
Thread: 139695015065280 Received from client: T1 Saying Hello

Thread: 139695015065280 Received from client: T1 permission to Dock

Client connected!
Thread: 139695006672576 Received from client: T2 establishing connection

Thread: 139695006672576 Received from client: T2 requesting Docking
Thread: 139695006672576 Client sent exit. Closing connection.
Client disconnected.

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 6041
#define MAX_BUFFER 1024



void *handle_client(void *arg) {
    int client_sock = *(int *)arg;
    free(arg);
    char buffer[MAX_BUFFER];
    int n;
    long long int tid = pthread_self();
    // reading the client msg

    while ((n = recv(client_sock, buffer, MAX_BUFFER, 0)) > 0) {

        buffer[n] = '\0';
         if (strncmp(buffer, "exit", 4) == 0) {
        printf("Thread: %lld Client sent exit. Closing connection.\n", tid);
        break;  // Break the loop and close the connection
    }
        printf("Thread: %lld Received from client: %s\n",tid, buffer);
          
        // ACK client
        send(client_sock, "ACK From SERVER\n", 17, 0);
    }

    // Close the socket when done
    close(client_sock);
    printf("Client disconnected.\n");
    return NULL;
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Step 1: Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Bind socket to address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Step 3: Listen for connections
    if (listen(server_sock, 5) < 0) {
        perror("listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Step 4: Accept and handle multiple clients concurrently using pthreads
    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected!\n");

        // Allocate memory for the client socket to pass it to the thread
        int *new_sock = malloc(sizeof(int));
        *new_sock = client_sock;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) != 0) {
            perror("pthread_create failed");
            free(new_sock);
        }

        // Detach the thread to free resources when it finishes
        pthread_detach(thread_id);
    }

    close(server_sock);
    return 0;
}
