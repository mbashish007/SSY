/*
Name: M B Ashish | Roll No: MT2024085

13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).

Output
$ ./a.out
No Input present in STDIN: Success

$ ./a.out
jjiiji
Input from STDIN : jjiiji
*/

#include <sys/select.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main() {
    fd_set read_fdSet;

    FD_SET(STDIN_FILENO,&read_fdSet);
    struct timeval timeOut ;
    timeOut.tv_sec = 10;
    timeOut.tv_usec = 0;

    int totalBytes = select(1, &read_fdSet, NULL, NULL, &timeOut);

    if(totalBytes == -1) {
        perror("ERROR");
        return -1;

    }


    if(totalBytes == 0) {
        perror("No Input present in STDIN");
        return 0;

    }
    char s[256];
    int readBytes = read(STDIN_FILENO, &s, 256);
    printf("Input from STDIN : %s \n", s);

    return 0;
}