/*
============================================================================
Name: 15.c 

Author: M B Ashish

Roll No: MT2024085

Description: 15. Write a simple program to send some data from parent to the child process.

Date: 21 September, 2024.
============================================================================

Output

Program started
Child pid: 104749 parent pid: 1681
Message from parent = Hello

============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <unistd.h>




int main() {
    printf("Program started\n");

    int fd[2];
   
    pipe(fd);

    if(!fork()) {
        printf("Child pid: %d parent pid: %d\n", getpid(), getppid());
        char buff[20];
        read(fd[0], buff, 20);
        printf("Message from parent = %s", buff);
    }
    else{
    write(fd[1], "Hello\n", 10);

    }
    return 0;
}