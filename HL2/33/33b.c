/*
============================================================================
Name: 33b.c 

Author: M B Ashish

Roll No: MT2024085

Description: 33. Write a program to communicate between two machines using socket.

Date: 21 September, 2024.
============================================================================

Output
 Enter Data
hello
msg from server: ACK from SERVER
 
Enter Data
cl2
msg from server: ACK from SERVER
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

 int main() {
    struct sockaddr_in serv;


    int sd;

    char buf[80];
    char wbuf[80];

    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr= INADDR_ANY;
    serv.sin_port= htons(6008);

    if(connect(sd, (void*) (&serv), sizeof(serv)) == -1) {
        perror("connect\n");
        exit(1);
    }

    while(1) {
        printf("Enter Data\n");
        fgets(wbuf, sizeof(wbuf), stdin);
        write(sd, wbuf, sizeof(wbuf));
        read(sd, buf, sizeof(buf));
        printf("msg from server: %s \n", buf);
    }
    
 }
