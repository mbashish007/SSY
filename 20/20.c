/*
============================================================================
Name: 20.c
Author: M B Ashish 
Roll No: MT2024085

Description: 20. Find out the priority of your running program. Modify the priority with nice command.

Date: 31 Aug, 2024.
============================================================================
Output
$ ./a.out
Current priority 0
priority after nice : -1
*/

#include <stdio.h>
       #include <unistd.h>
#include <stdlib.h>
       #include <sys/resource.h>

int main() {
    int priority = getpriority(PRIO_PROCESS,0);
    printf("Current priority %d\n", priority);
    if(priority != -19)
    priority--;
    priority = nice(priority);
    printf("priority after nice : %d", priority);

    return 0;
}
