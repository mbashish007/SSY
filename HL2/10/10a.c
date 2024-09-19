/*
============================================================================
Name: 10a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 10. Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE

Date: 21 September, 2024.
============================================================================

Output

Program started
Signal: 11 caught.


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

    sa.sa_sigaction = handler;
    
     if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    pause();
    
    return 0;
}