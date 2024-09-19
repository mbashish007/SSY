/*
============================================================================
Name: 8b.c 

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
^CRecieved signal: 2 
^CRecieved signal: 2 
^CRecieved signal: 2 
^CRecieved signal: 2 
^Z
[1]+  Stopped 
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
    signal(SIGINT,sigHandler);
    
    while(1)
        pause();
    
    return 0;
}