/*
Name: M B Ashish | Roll No: MT2024085

11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl


Output

$ ./a.out f7

$ cat f7
written using dup fd written using dup2 fd written using fctnl fd
*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * args[]) {

    int fd = open(args[1], O_RDWR | O_CREAT , 0700);

    if(fd == -1) {
        perror("File Opening Error.");
    }

    int fd1 = dup(fd);
    char  s[255] = "written using dup fd ";
    if(write(fd1, s, 255 ) < 0) {
        perror("dup");
        return -1;
    }

    int fd2 = dup2(fd, 99) ;
    char  t[255] = "written using dup2 fd ";
    if(write(fd1, t, 255) < 0) {
        perror("dup");
        return -1;
    }

       int fd3= fcntl(fd, F_DUPFD) ;
    char  u[255] = "written using fctnl fd ";
    if(write(fd3, u, 255) < 0) {
        perror("dup");
        return -1;
    }

    close(fd);
}
