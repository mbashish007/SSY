/*

============================================================================
Name: 10.c
Author: M B Ashish 
Roll No: MT2024085

Description: 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.


Date: 31 Aug, 2024.
============================================================================

Output

$ ./a.out f3
a
bytes written: 10offset = 20
quick
bytes written: 10offset = 40
brown 
bytes written: 10offset = 60
fox
bytes written: 10offset = 80
^C

$ od -a f3
0000000   a nul nul nul nul nul nul nul nul nul nul nul nul nul nul nul
0000020 nul nul nul nul   q   u   i   c   k nul nul nul nul nul nul nul
0000040 nul nul nul nul nul nul nul nul   b   r   o   w   n nul nul nul
0000060 nul nul nul nul nul nul nul nul nul nul nul nul   f   o   x nul
0000100   n nul nul nul nul nul
0000106
*/

/*
lseek return
Upon successful completion, lseek() returns the resulting offset location as measured in bytes from the beginning of the file.  On error, the  value
(off_t) -1 is returned and errno is set to indicate the error.*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

const char EOL = '\n';
int main(int argc, char* args[]) {
    int fd = open(args[1], O_RDWR );
    if(fd == -1) {
        perror("Program");
        return -1;
    }

    while(1) {
        char ioBuffer[10];
        scanf("%s", ioBuffer); 
        // printf("%s", ioBuffer);

        int writeBytes = write(fd, ioBuffer, 10);
        printf("bytes written: %d", writeBytes);
        if(writeBytes == -1) {
            perror("Write Error");
            return -1;
        }
        long offset = lseek(fd, 10, SEEK_CUR);
        printf("offset = %ld\n", offset);
    }
    return 0;
}
