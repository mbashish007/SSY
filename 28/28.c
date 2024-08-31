/*
============================================================================
Name: 28.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q28.Write a program to get maximum and minimum real time priority.
a. execl
b. execlp
c. execle
d. execv
e. execvp

Date: 31 Aug, 2024.
============================================================================

Output
$ ./a.out
Max FIFO PR : 99
Min FIFO PR : 1
Max RR PR : 99
Min RR PR : 1

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sched.h>


int main(int argc, char * args[]) {
  
  int maxFifo, minFifo, maxRR, minRR;
  maxFifo = sched_get_priority_max(SCHED_FIFO);
  minFifo = sched_get_priority_min(SCHED_FIFO);

  maxRR = sched_get_priority_max(SCHED_RR);
  minRR = sched_get_priority_min(SCHED_RR);

  printf("Max FIFO PR : %d\n",maxFifo);
  printf("Min FIFO PR : %d\n",minFifo);

  printf("Max RR PR : %d\n",maxRR);
  printf("Min RR PR : %d\n",minRR);
    return 0;
} 