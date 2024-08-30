/*
Name: 22.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Output
$ ./a.out f2
parent process id: 13845
child process id: 13846

$ cat f2
parent process id: 13845 
child process id: 13846 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * args[]) {

    int fd = open(args[1], O_WRONLY | O_CREAT, 0700);

    
    int cpid = fork();
    
    if(cpid == -1) {
        perror("fork error\n");
        return -1;
    }

    if(cpid == 0) {
        printf("child process id: %d\n", getpid());
        char s[40];
        snprintf(s, 40, "child process id: %d \n", getpid());
        write(fd, s, 40);
        
    }else {
        printf("parent process id: %d\n", getpid());
        char s[40];
        snprintf(s, 40, "parent process id: %d \n", getpid());
        write(fd, s, 40);
        }
}
