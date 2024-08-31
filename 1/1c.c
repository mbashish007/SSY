/*
============================================================================
Name: 1c.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31 Aug, 2024.
============================================================================

Output:
$ ./a.out 
Enter fifo file name 
f2
Fifo file f2 created 

Use:

Terminal 1: cat > f2
Terminal 2: more f2
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {

    char fifo_file_name[256];


    printf("Enter fifo file name \n");
    scanf("%s", fifo_file_name);

    if(mkfifo(fifo_file_name, 744) == 0) {
        printf("Fifo file %s created ", fifo_file_name);
    }
    else perror("Fifo error");
} 