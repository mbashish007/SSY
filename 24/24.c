/*

============================================================================
Name: 24.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q24. Write a program to create an orphan process.

Date: 31 Aug, 2024.
============================================================================
Output
$ ./a.out 
parent process id: 25602

child process id: 25603 Parent process id: 25602
child process id: 25603 Parent process id: 1667

$ps -eaf 
m-b-ash+    1667       1  0 13:08 ?        00:00:00 /lib/systemd/systemd --user

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
        while(1) printf("child process id: %d Parent process id: %d n", getpid(), getppid());
    }
    else {
        printf("parent process id: %d\n", getpid());
        
        }
}