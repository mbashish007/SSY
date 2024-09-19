/*
============================================================================
Name: 8a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)

Date: 21 September, 2024.
============================================================================

Output

Program started
Recieved signal: 11 

******************
terminal 2
kill -11 10949
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include<signal.h>


void sigHandler(int signum) {
    printf("Recieved signal: %d \n", signum);
}

int main() {
    printf("Program started\n");
    signal(SIGSEGV,sigHandler);

    pause();
    return 0;
}