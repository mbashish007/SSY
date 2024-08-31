/*
Name: 27c.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

Output
execle system call output
.:
total 32
-rw-rw-r-- 1 m-b-ashish m-b-ashish   998 Aug 31 15:44 27a.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   833 Aug 31 16:29 27b.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   696 Aug 31 16:31 27c.c
-rwxrwxr-x 1 m-b-ashish m-b-ashish 16000 Aug 31 16:31 a.out
drwxrwxr-x 2 m-b-ashish m-b-ashish  4096 Aug 31 15:25 d1

./d1:
total 0
-rw-rw-r-- 1 m-b-ashish m-b-ashish 0 Aug 31 15:25 f1


*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * args[]) {
   printf("\nexecle system call output\n");

    execle("/usr/bin/ls", "ls", "-Rl", NULL, NULL);
    return 0;
} 