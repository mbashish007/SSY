/*
============================================================================
Name: 11.c 

Author: M B Ashish

Roll No: MT2024085

Description: 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

Date: 21 September, 2024.
============================================================================

Output

Program started
SIGINT will be ignored
^C^CSIGINT restored to default behaviour
^C


============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handler(int sig, siginfo_t *info, void *ucontext)
           {
               printf("Signal: %d caught.\n", sig);
           }

int main() {
    printf("Program started\n");

    struct sigaction sa;

    sa.sa_handler = SIG_IGN;
    printf("SIGINT will be ignored\n");
     if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i< 1000000000; i++);

    sa.sa_handler = SIG_DFL;
    printf("SIGINT restored to default behaviour\n");
     if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    pause();
    
    return 0;
}