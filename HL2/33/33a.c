/*
============================================================================
Name: 33a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 33. Write a program to communicate between two machines using socket.

Date: 21 September, 2024.
============================================================================

Output
./server
msg from client: hello
 
msg from client: cl2
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <signal.h>

int sd = -1;

void handle_sigint(int sig) {
  printf("Received Sig = %d, sd = %d\n", sig, sd);
    close(sd);
    exit(0);  // Exit the program
}

 int main() {
    struct sockaddr_in serv, cli;


    int sz, nsd;
    signal(SIGINT, handle_sigint);
    char buf[80];
    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr= INADDR_ANY;
    serv.sin_port= htons(6008);
    int opt = 1;

   if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
      perror("setsockopt");
      close(sd);
      exit(EXIT_FAILURE);
   }
   
    if(bind(sd, (void*) (&serv), sizeof(serv)) < 0) {
      
      perror("bind\n");
      close(sd);
      exit(1);
    }

    if(listen(sd, 5)<0) {
      perror("listen\n");
      exit(1);
    }
    sz = sizeof(cli);
    nsd = accept(sd, (void*) (&cli), &sz);
    if(nsd == -1) {
      perror("accept");
    }
     printf("Client accepted %d\n", nsd);
     while(1) {
          read(nsd, buf, sizeof(buf));
         buf[sizeof(buf)] = '\0';
      printf("msg from client: %s \n", buf);
      write(nsd, "ACK from SERVER\n", 17);
     }
           
      

    close(sd);
 }
