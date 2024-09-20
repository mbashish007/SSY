/*
============================================================================
Name: 17c.c 

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
     22     191    1208

============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>



int main() {
    printf("Program started\n");

    int fd[2];
   
    pipe(fd);

    if(!fork()) {
        close(fd[0]);
        close(STDOUT_FILENO);
        fcntl(fd[1],F_DUPFD,STDOUT_FILENO);
      
        
        execl("/usr/bin/ls", "ls","-l", (char*)NULL);

    }
    else{
        close(fd[1]);
        close(STDIN_FILENO);
        fcntl(fd[0],F_DUPFD,STDIN_FILENO);
        execl("/usr/bin/wc", "wc", (char*)NULL);
    
        

    }
    return 0;
}