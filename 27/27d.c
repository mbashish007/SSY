/*
Name: 27d.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

Output
execv system call output
.:
total 40
-rw-rw-r-- 1 m-b-ashish m-b-ashish   977 Aug 31 16:32 27a.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   812 Aug 31 16:32 27b.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   810 Aug 31 16:32 27c.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   833 Aug 31 16:36 27d.c
-rw-rw-r-- 1 m-b-ashish m-b-ashish   810 Aug 31 16:34 27e.c
-rwxrwxr-x 1 m-b-ashish m-b-ashish 16048 Aug 31 16:36 a.out
drwxrwxr-x 2 m-b-ashish m-b-ashish  4096 Aug 31 15:25 d1

./d1:
total 0
-rw-rw-r-- 1 m-b-ashish m-b-ashish 0 Aug 31 15:25 f1

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * args[]) {
   printf("\nexecv system call output\n");
   char* lsargs[4] = {"ls", "-Rl", NULL};

    execv("/usr/bin/ls", lsargs);
    return 0;
} 