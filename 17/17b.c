/*

============================================================================
Name: 17b.c
Author: M B Ashish 
Roll No: MT2024085

Description: 17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

Date: 31 Aug, 2024.
============================================================================
Output
$ ./a.out ticket3
Before entring CS
Inside CS 
Ticket No. current value: 3 
Ticket value after increment : 4

$ ./a.out ticket3
Before entring CS
Inside CS 
Ticket No. current value: 4 
Ticket value after increment : 5
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

    int tic;

 lock.l_type=F_WRLCK;
    lock.l_whence= SEEK_SET;
    lock.l_start=0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before entring CS\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside CS \n");
    int rB = read(fd, &tic, sizeof(tic));
    printf("Ticket No. current value: %d \n", tic);
    tic++;

    lseek(fd, 0, SEEK_SET);// always update the first value
    
    int wB = write(fd, &tic, sizeof(tic));
    printf("Ticket value after increment : %d\n", tic);

    if(wB < 0) {
        perror("Write Error");
        return -1;
    }

   lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);
 return 0;   
}
