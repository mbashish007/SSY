/*
Name: M B Ashish | Roll No: MT2024085
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

Output
$ ./a.out test1
PID = 31945
Before entring CS RD
Inside CS 
Enter to Unlock RD
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * args[]) {
    struct flock lock;

    int fd = open(args[1], O_RDWR);
    printf("PID = %d\n", getpid());

    lock.l_type=F_RDLCK;
    lock.l_whence= SEEK_SET;
    lock.l_start=0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before entring CS RD\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside CS \n");
    printf("Enter to Unlock RD\n");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Unlocked");

    return 0;

}
