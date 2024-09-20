/*
============================================================================
Name: 17b.c 

Author: M B Ashish

Roll No: MT2024085

Description: 18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

Date: 21 September, 2024.
============================================================================

Output

Program started
      1       9      59

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Program started\n");

    int fd[2];    // Pipe between ls and grep
    int fd2[2];   // Pipe between grep and wc

    // Create the first pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    // Fork the first child for "ls -l"
    if (fork() == 0) {
        
        close(fd[0]);         
        dup2(fd[1], STDOUT_FILENO);  
        close(fd[1]);         

        execlp("ls", "ls", "-l", (char *)NULL);  
        perror("execlp ls");  
        exit(1);
    }

    // Create the second pipe
    if (pipe(fd2) == -1) {
        perror("pipe");
        exit(1);
    }

    // Fork the second child for "grep ^d"
    if (fork() == 0) {
        
        close(fd[1]);         
        dup2(fd[0], STDIN_FILENO);  
        close(fd[0]);        

        close(fd2[0]);        
        dup2(fd2[1], STDOUT_FILENO);  
        close(fd2[1]);       

        execlp("grep", "grep", "^d", (char *)NULL);  
        perror("execlp grep");  
        exit(1);
    }

    // In parent process
    close(fd[0]);  
    close(fd[1]);  
    close(fd2[1]); 

    // Fork the third child for "wc -l"
    if (fork() == 0) {
        
        dup2(fd2[0], STDIN_FILENO);  
        close(fd2[0]);  

        execlp("wc", "wc", (char *)NULL);  
        perror("execlp wc"); 
        exit(1);
    }

 
    close(fd2[0]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
