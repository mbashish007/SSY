
/*
============================================================================
Name: 1a.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)

Date: 31 Aug, 2024.
============================================================================

Output: ./a.out
Enter target path 
somefile
Enter symlink path 
sym1
Symlink created
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {
    printf("Hello world\n");

    char target[256];
    char symlink_st[256];

    printf("Enter target path \n");
    scanf("%s", target);
    printf("Enter symlink path \n");
    scanf("%s", symlink_st);

    if(symlink(target, symlink_st) == 0) {
        printf("Symlink created");
    }
    else perror("Symlink error");
} 