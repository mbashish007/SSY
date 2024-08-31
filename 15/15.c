/*

============================================================================
Name: 15.c
Author: M B Ashish 
Roll No: MT2024085

Description: 15. Write a program to display the environmental variable of the user (use environ).man 

Date: 31 Aug, 2024.
============================================================================
Output
$ ./a.out
USER = m-b-ashish
LOGNAME = m-b-ashish
LANG = en_US.UTF-8
PWD = /home/m-b-ashish/Documents/SSY/15
SHELL = /bin/bash
PAGER = (null)
TERM = xterm-256color
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;

int main() {
    char **env = environ;
    printf("USER = %s\n", getenv("USER"));
    printf("LOGNAME = %s\n", getenv("LOGNAME"));
    printf("LANG = %s\n", getenv("LANG"));
    printf("PWD = %s\n", getenv("PWD"));
    printf("SHELL = %s\n", getenv("SHELL"));
    printf("PAGER = %s\n", getenv("PAGER"));
    printf("TERM = %s\n", getenv("TERM"));






    return 0;
}