/*
============================================================================
Name: 29.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q29.Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date: 31 Aug, 2024.
============================================================================

Output
$ ./a.out
Current Scheduler 
Scheduler : SCHED_OTHER 
changing scheduler to FIFO
Current Scheduler 
Scheduler : SCHED_FIFO 
changing scheduler to RR
Current Scheduler 
Scheduler : SCHED_RR 

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sched.h>

void printSchedPolicy(int schd) {
    switch (schd)
    {
    case SCHED_OTHER: printf("Scheduler : SCHED_OTHER \n");
        break;
    
    case SCHED_FIFO: printf("Scheduler : SCHED_FIFO \n");
        break;
    
    case SCHED_RR : printf("Scheduler : SCHED_RR \n");
        break;
    
    default:
        break;
    }
}

int main(int argc, char * args[]) {
  
    int pid = getpid();
    struct sched_param schedulerPriority;
    int schd = sched_getscheduler(pid); 
    if(schd ==-1) {
        perror("Get Scheduler\n");
        return -1;
    }
    printf("Current Scheduler \n");
    printSchedPolicy(schd);

    schedulerPriority.sched_priority = 1;

    printf("changing scheduler to FIFO\n");
    if(sched_setscheduler(pid, SCHED_FIFO, &schedulerPriority) == -1) {
        perror("Set Scheduler\n");
        return -1;
    }
    schd = sched_getscheduler(pid); 
    if(schd ==-1) {
        perror("Get Scheduler\n");
        return -1;
    }
    printf("Current Scheduler \n");
    printSchedPolicy(schd);

    printf("changing scheduler to RR\n");
    if(sched_setscheduler(pid, SCHED_RR, &schedulerPriority) == -1) {
        perror("Set Scheduler\n");
        return -1;
    }
    schd = sched_getscheduler(pid); 
    if(schd ==-1) {
        perror("Get Scheduler\n");
        return -1;
    }
    printf("Current Scheduler \n");
    printSchedPolicy(schd);


    return 0;
} 