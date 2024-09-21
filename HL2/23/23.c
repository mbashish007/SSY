/*
============================================================================
Name: 23.c 

Author: M B Ashish

Roll No: MT2024085

Description: 23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

Date: 21 September, 2024.
============================================================================

Output

Maximum Open files : 1048576
pipe(circular buffer) size: 65536 bytes
*/

#define _GNU_SOURCE

#include <sys/resource.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <linux/fcntl.h>
// #include <linux/fcntl.h>

int main() {
    struct rlimit limit;

    // max open file desc
    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Maximum Open files : %ld\n", limit.rlim_cur);
    } else {
        perror("getrlimit");
        return 1;
    }

    // Create a pipe
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    // pipe size using fcntl
    int pipe_size = fcntl(pipe_fd[0], F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("fcntl");
        return 1;
    }

    printf("pipe(circular buffer) size: %d bytes\n", pipe_size);

    // Close the pipe file descriptors
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    return 0;
}