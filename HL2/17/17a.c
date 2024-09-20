/*
============================================================================
Name: 17a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 17. Write a program to execute ls -l | wc.
                a. use dup
                b. use dup2
                c. use fcntl

Date: 21 September, 2024.
============================================================================

Output

Program started
      4      29     188

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
        close(fd[0]);
        close(STDOUT_FILENO);
        dup(fd[1]);
      
        
        execlp("/usr/bin/ls", "ls","-l", (char*)NULL);

    }
    else{
        close(fd[1]);
        close(STDIN_FILENO);
        dup(fd[0]);
        execlp("/usr/bin/wc", "wc", (char*)NULL);
    
        

    }
    return 0;
}