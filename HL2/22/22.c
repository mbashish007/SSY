/*
============================================================================
Name: 22.c 

Author: M B Ashish

Roll No: MT2024085

Description: 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.

Date: 21 September, 2024.
============================================================================

Output

mkfifo: File exists
Waiting
No Input present in myfifo1: File exists

mkfifo: File exists
Waiting
Received: f
*/

#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_path = "myfifo1";  // Path to the FIFO file
    char buffer1[100];

    if (mkfifo(fifo_path, 0777) == -1) {
        perror("mkfifo");
    }

    
    int fd = open(fifo_path, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

    fd_set read_fdSet;

    FD_SET(fd,&read_fdSet);
    struct timeval timeOut ;
    timeOut.tv_sec = 10;
    timeOut.tv_usec = 0;

    printf("Waiting\n");

    int totalBytes = select(fd+1, &read_fdSet, NULL, NULL, &timeOut);

    if(totalBytes == -1) {
        perror("ERROR");
        return -1;

    }


    if(totalBytes == 0) {
        perror("No Input present in myfifo1");
        return 0;

    }

        int bytes_read = read(fd, buffer1, sizeof(buffer1));
        if (bytes_read > 0) {
            printf("Received: %s", buffer1);
        }


    return 0;
}
