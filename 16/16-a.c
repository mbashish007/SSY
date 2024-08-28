/*
Name: M B Ashish | Roll No: MT2024085
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

Output
$ ./o1 test2
PID = 31064Before entring CS
Inside CS 
Enter to Unlock 


Unlocked

$ ./o2 test2
PID = 31105Before entring CS
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
    printf("PID = %d", getpid());

    lock.l_type=F_WRLCK;
    lock.l_whence= SEEK_SET;
    lock.l_start=0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before entring CS\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside CS \n");
    printf("Enter to Unlock \n");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Unlocked");

    return 0;

}
