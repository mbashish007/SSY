/*
Name: M B Ashish | Roll No: MT2024085

7. Write a program to copy file1 into file2 ($cp file1 file2).

Output
$ cat f1
Hi
Hello World
Salvador Munde

$ ./a.out f1 f2

$ cat f2
Hi
Hello World
Salvador Munde
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *args[]) {

    int fd1 = open(args[1], O_RDONLY);

    if(fd1 == -1) {
        perror("File 1 error");
        return -1;
    }

    int fd2 = open(args[2], O_WRONLY | O_CREAT | O_EXCL , 0700) ;

        if(fd2 == -1) {
            perror("File 2 error");
            return -1;
        }

    char* buffer = (char *) malloc(1024);
    int readSize = 0;

    while((readSize = read(fd1, buffer, 1024)) > 0) {
        write(fd2, buffer, readSize);
    }

    close(fd1);
    close(fd2);

    return 0;
    
}