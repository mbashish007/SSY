/*
============================================================================
Name: 12.c 

Author: M B Ashish

Roll No: MT2024085

Description: 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process

Date: 21 September, 2024.
============================================================================

Output

Program started
parent process pid = 91602
child pid: 91603, parent pid: 91602
Killed
child pid: 91603, parent pid: 1681


============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int main() {
    printf("Program started\n");

    if(!fork()) {
        sleep(2);
         printf("child pid: %d, parent pid: %d\n", getpid(), getppid());

        kill(getppid(), SIGKILL); 
        sleep(5);
        printf("child pid: %d, parent pid: %d\n", getpid(), getppid());
    }
    else {
       printf("parent process pid = %d\n", getpid());
       sleep(10);

    }

    return 0;
}