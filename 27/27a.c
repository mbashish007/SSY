/*
Name: 27a.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

Output
$ ./a.out
.:
total 24
-rw-rw-r-- 1 m-b-ashish m-b-ashish   426 Aug 31 15:29 27a.c
-rwxrwxr-x 1 m-b-ashish m-b-ashish 15960 Aug 31 15:29 a.out
drwxrwxr-x 2 m-b-ashish m-b-ashish  4096 Aug 31 15:25 d1

./d1:
total 0
-rw-rw-r-- 1 m-b-ashish m-b-ashish 0 Aug 31 15:25 f1


*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void fexeclp(){
    printf("\nexeclp system call output\n");
    execlp("/usr/bin/ls", "ls", "-Rl", (char *)NULL);
}

int main(int argc, char * args[]) {
    printf("\nexecl system call output1\n");
    execl("/usr/bin/ls", "ls", "-Rl", (char *)NULL);
    perror("execl counter");

    fexeclp();

        fexeclp();


    printf("\nexecle system call output\n");
    execle("/usr/bin/ls", "ls", "-Rl", (char *)NULL);

    // execle()
    return 0;
} 