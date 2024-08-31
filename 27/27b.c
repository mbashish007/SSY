/*
Name: 27b.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

Output
execlp system call output
.:
total 32
-rw-rw-r-- 1 m-b-ashish m-b-ashish   998 Aug 31 15:44 27a.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   697 Aug 31 16:28 27b.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   697 Aug 31 16:28 27c.c
-rwxrwxr-x 1 m-b-ashish m-b-ashish 16000 Aug 31 16:29 a.out
drwxrwxr-x 2 m-b-ashish m-b-ashish  4096 Aug 31 15:25 d1

./d1:
total 0
-rw-rw-r-- 1 m-b-ashish m-b-ashish 0 Aug 31 15:25 f1


*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char * args[]) {
   printf("\nexeclp system call output\n");
    execlp("/usr/bin/ls", "ls", "-Rl", (char *)NULL);
    return 0;
} 