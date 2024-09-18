/*
============================================================================
Name: 1a.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q1. 1a. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF.

Date: 21 September, 2024.
============================================================================

Output

Starting Program
current time secs: 1726660813 usec: 817547
Signal received: 14 
current time secs: 1726660823 usec: 817634
*/

#include <sys/time.h>
#include <stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_handler(int sig) {
    printf("Signal received: %d \n", sig);
    
    struct  timeval currTime;
    
    gettimeofday(&currTime, NULL);

    printf("current time secs: %ld usec: %ld\n", currTime.tv_sec, currTime.tv_usec);
    
}
int main() {

    struct  timeval currTime;
    printf("Starting Program\n");
    gettimeofday(&currTime, NULL);
     printf("current time secs: %ld usec: %ld\n", currTime.tv_sec, currTime.tv_usec);
     
     signal(SIGALRM, signal_handler);
    struct itimerval timer;

    //single shot timer
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;    

    //timer value
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_REAL,&timer, NULL);

    pause();

    
}
    
