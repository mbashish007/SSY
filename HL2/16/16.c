/*
============================================================================
Name: 16.c 

Author: M B Ashish

Roll No: MT2024085

Description: 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.

Date: 21 September, 2024.
============================================================================

Output

Program started
Child pid: 11171 parent pid: 11170
Message from parent = Hello Son

Message from child = Hello Mother!

============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <unistd.h>




int main() {
    printf("Program started\n");

    int fd1[2]; //parent 2 child pipe
    int fd2[2]; // child 2 parent pipe

   if((pipe(fd1) == -1) || (pipe(fd2) == -1)) {
    perror("pipe error\n");
    return -1;
   }

    if(!fork()) {
        close(fd1[1]); //p2c pipe input
        close(fd2[0]); //c2p out
        sleep(2);
        printf("Child pid: %d parent pid: %d\n", getpid(), getppid());
        char buff[20];
        read(fd1[0], buff, 20);
        printf("Message from parent = %s\n", buff);

        // char buff1[20] = "Hello Mother!\n";
        write(fd2[1], "Hello Mother!\n", 20);

        close(fd1[0]); //p2c out
        close(fd2[1]); //c2p in
        

    }
    else{
        close(fd1[0]); //p2c out
        close(fd2[1]); //c2p in
        
        write(fd1[1], "Hello Son\n", 20);

        char buff[20];
        read(fd2[0], buff, 20);
        printf("Message from child = %s\n", buff);

        close(fd1[1]); //p2c pipe input
        close(fd2[0]); //c2p out

    }
    // return 0;
}