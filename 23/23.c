/*

============================================================================
Name: 23.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q23. Write a program to create a Zombie state of the running program.

Date: 31 Aug, 2024.
============================================================================
Output
$ ./a.out 
parent process id: 20655
child process id: 20657

$ ps -eaf
m-b-ash+   20655    4145 99 20:57 pts/0    00:04:51 ./a.out
m-b-ash+   20657   20655  0 20:57 pts/0    00:00:00 [a.out] <defunct>

$ top -b -n 10 > top.txt

top - 20:58:17 up  7:50,  2 users,  load average: 0.87, 1.00, 0.97
Tasks: 311 total,   2 running, 307 sleeping,   1 stopped,   1 zombie
%Cpu(s): 15.5 us,  1.2 sy,  0.0 ni, 71.4 id, 10.7 wa,  0.0 hi,  1.2 si,  0.0 st 

20657 m-b-ash+  20   0       0      0      0 Z   0.0   0.0   0:00.00 a.out
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

    int cpid = fork();

    if(cpid == -1) {
        perror("fork error\n");
        return -1;
    }

    if(cpid == 0) {
        printf("child process id: %d\n", getpid());
    }
    else {
        printf("parent process id: %d\n", getpid());
        while(1);
        }
}