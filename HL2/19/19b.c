/*
============================================================================
Name: 19a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function

Date: 21 September, 2024.
============================================================================

Output

File fifo1 Created Successfully
File fifo2 Created Successfully

prwx------ 1 m-b-ashish m-b-ashish     0 Sep 20 23:48 fifo1
prwx------ 1 m-b-ashish m-b-ashish     0 Sep 20 23:48 fifo2
============================================================================
*/

#include <sys/types.h>
 #include <fcntl.h>           /* Definition of AT_* constants */
       #include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/stat.h>
#include <stdlib.h>

int main() {
      if (mknod("fifo1", S_IFIFO | 0700, 0) == -1) {
        perror("mknod");
        return 1;
    }   else {
        printf("File fifo1 Created Successfully\n");
    }
 if (mkfifo("fifo2",  0700) == -1) {
        perror("mkfifo");
        return 1;
    }   else {
        printf("File fifo2 Created Successfully\n");
    }

}