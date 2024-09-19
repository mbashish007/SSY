/*
============================================================================
Name: 8g.c 

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
Recieved signal: 27 

============================================================================
*/

#include <stdio.h>
#include<signal.h>
#include<unistd.h>
#include <sys/time.h>


void sigHandler(int signum) {
    printf("Recieved signal: %d \n", signum);
}

int main() {
    printf("Program started\n");
    struct  timeval currTime;
     
    signal(SIGPROF, sigHandler);
    struct itimerval timer;

    //single shot timer
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;    

    //timer value
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_PROF,&timer, NULL);

    while(1);
    return 0;
}