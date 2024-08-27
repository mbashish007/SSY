/*
Name: M B Ashish | Roll No: MT2024085

6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Output
$ ./a.out

Hello
Hello

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char *input = (char *) malloc(256);

    int readBytes = read(0, input, 256);
    if(readBytes < 0) {
        write(STDOUT_FILENO, "Error Reading", 256);
        return -1;
    }
    
    int writeBytes = write(STDOUT_FILENO, input, readBytes);
     if(writeBytes < 0) {
        write(STDOUT_FILENO, "Error Writing", 256);
        return -1;
    }
}