/*
Name: 25.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

Output
$ ./a.out 
parent process id: 39169
child process id: 39170 Parent process id: 39169 
child process id: 39171 Parent process id: 39169 
child process id: 39172 Parent process id: 39169 
parent exiting 39169 

*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
       #include <sys/wait.h>


int main() {
    int cpid, cpid1, cpid2;
    cpid = fork();

    if(cpid == -1) {
        perror("fork error\n");
        return -1;
    }

    if(cpid == 0) {
        for(int i =0; i<1000;i++); 
        printf("child process id: %d Parent process id: %d \n", getpid(), getppid());
    }
    else {
        printf("parent process id: %d\n", getpid());
        cpid1 = fork();
        if(cpid1 == 0) {
        for(int i =0; i<1000;i++); 
        printf("child process id: %d Parent process id: %d \n", getpid(), getppid());
            }
            else {
                cpid2 = fork();
                if(cpid2 == 0) {
                for(int i =0; i<1000;i++); 
                printf("child process id: %d Parent process id: %d \n", getpid(), getppid());
            }
            else {
                int wstatus;
                waitpid(cpid2, &wstatus,0); // waiting for last process;
                printf("parent exiting %d \n",getpid());
            }
        }
}
return 0;
}