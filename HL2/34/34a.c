/*
============================================================================
Name: 34a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 34. Write a program to create a concurrent server.
                a. use fork
                b. use pthread_create

Date: 21 September, 2024.
============================================================================

Output
Server listening on port 6040...
Client connected!
Received on child:11511 from client: hello

Client connected!
Received on child:11659 from client: t2 communicating

Received on child:11511 from client: t1 communicating
PID: 11511 Client sent exit. Closing connection.
Client disconnected.
                                                                                                                                                                

Received on child:11511 from client: ok
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 6040
#define MAX_BUFFER 1024

void handle_client(int client_sock) {
    char buffer[MAX_BUFFER];
    int n;
    int pid = getpid();
    // Communicate with the client
    while ((n = recv(client_sock, buffer, MAX_BUFFER, 0)) > 0) {
        buffer[n] = '\0';
        if (strncmp(buffer, "exit", 4) == 0) {
        printf("PID: %d Client sent exit. Closing connection.\n", pid);
        break;  // Break the loop and close the connection
        }
        printf("Received on child:%d from client: %s\n", pid,buffer);

        // Echo message back to client
        send(client_sock, "ACK from Server\n", 17, 0);
    }

    
    close(client_sock);
    printf("Client disconnected.\n");
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

   
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_sock, 5) < 0) {
        perror("listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected!\n");

        // child process to handle the client
        if (fork() == 0) {
            close(server_sock); 
            handle_client(client_sock);
            exit(0);  
        }

        close(client_sock);  
    }

    close(server_sock);
    return 0;
}
