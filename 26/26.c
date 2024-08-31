/*
Name: 26.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Output
$ ./a.out 
program
#include<stdio.h>

int main(int argc, char* args[]) {
    printf("Hello %s \n", args[1]);
}

$ ./26.out a.out Ashish
Hello Ashish 


*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>


int main(int argc, char * args[]) {
    execl(args[1], args[1] ,args[2], (char *) NULL);
    return 0;
} 