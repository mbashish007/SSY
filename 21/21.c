/*
Name: M B Ashish | Roll No: MT2024085

21. Write a program, call fork and print the parent and child process id.

Output
$ ./a.out
parent process id: 5640
child process id: 5641
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
    }else printf("parent process id: %d\n", getpid());
}
