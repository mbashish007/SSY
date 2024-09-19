/*
============================================================================
Name: 14.c 

Author: M B Ashish

Roll No: MT2024085

Description: 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

Date: 21 September, 2024.
============================================================================

Output

Program started
Pipe value = Hello

============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <unistd.h>




int main(int argc, char* argv) {
    printf("Program started\n");

    int fd[2];
    char buff[10];
    pipe(fd);
    write(fd[1], "Hello\n", 10);
    read(fd[0], buff, 10);
    printf("Pipe value = %s", buff);
    return 0;
}