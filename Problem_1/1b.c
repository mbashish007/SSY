/*
============================================================================
Name: 1b.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31 Aug, 2024.
============================================================================

Output:
Enter target path 
somefile
Enter hardlink path 
hlink1
HardLink created
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {

    char target[256];
    char hardlink_st[256];

    printf("Enter target path \n");
    scanf("%s", target);
    printf("Enter hardlink path \n");
    scanf("%s", hardlink_st);

    if(link(target, hardlink_st) == 0) {
        printf("HardLink created");
    }
    else perror("HardLink error");
} 