/*
Name: M B Ashish | Roll No: MT2024085

17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

Output
$./a.out ticket3
Written to file ticket successfully
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * args[]) {

    int fd = open(args[1], O_WRONLY | O_CREAT, 0744);

    int ticketno = 1;
    int *tic = &ticketno;

    int wB = write(fd, tic, sizeof(ticketno));


    if(wB < 0) {
        perror("Write Error");
        return -1;
    }
    close(fd);
    printf("Written to file %s successfully\n", args[1]);
 return 0;   
}
