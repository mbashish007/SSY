/*
============================================================================
Name: 17b.c 

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
     20     173    1088

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
        dup2(fd[1],STDOUT_FILENO);
      
        
        execlp("/usr/bin/ls", "ls","-l", (char*)NULL);

    }
    else{
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("/usr/bin/wc", "wc", (char*)NULL);
    
        

    }
    return 0;
}