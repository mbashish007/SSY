/*
============================================================================
Name: 13a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 21 September, 2024.
============================================================================

Output

$ ./13a
Program started
Process id: 97988

[13]+  Stopped                 ./13a


============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handler(int sig)
           {
               printf("Signal: %d caught.\n", sig);
           }

int main() {
    printf("Program started\n");
    printf("Process id: %d\n", getpid());
    // struct sigaction sa;

    // sa.sa_sigaction = handler;
  
     signal(SIGSTOP, handler);

    while(1);
    
    return 0;
}