/*

============================================================================
Name: 5.c
Author: M B Ashish 

Roll No: MT2024085

5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

Date: 31 Aug, 2024.
============================================================================

Output
$ ./a.out

pid: 9793

/proc/9793/fd$ ls -llh | head
total 0
lrwx------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 0 -> /dev/pts/3
l-wx------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 1 -> pipe:[1134288]
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 10 -> /home/m-b-ashish/Documents/SSY/5/text3
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 100 -> /home/m-b-ashish/Documents/SSY/5/text3
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 1000 -> /home/m-b-ashish/Documents/SSY/5/text2
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 10000 -> /home/m-b-ashish/Documents/SSY/5/text2
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 100000 -> /home/m-b-ashish/Documents/SSY/5/text2
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 1000000 -> /home/m-b-ashish/Documents/SSY/5/text2
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:55 1000001 -> /home/m-b-ashish/Documents/SSY/5/text3
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000000 -> /home/m-b-ashish/Documents/SSY/5/text2
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000001 -> /home/m-b-ashish/Documents/SSY/5/text3
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000002 -> /home/m-b-ashish/Documents/SSY/5/text4
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000003 -> /home/m-b-ashish/Documents/SSY/5/text5
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000004 -> /home/m-b-ashish/Documents/SSY/5/text1
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000005 -> /home/m-b-ashish/Documents/SSY/5/text2
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000006 -> /home/m-b-ashish/Documents/SSY/5/text3
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000007 -> /home/m-b-ashish/Documents/SSY/5/text4
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000008 -> /home/m-b-ashish/Documents/SSY/5/text5
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000009 -> /home/m-b-ashish/Documents/SSY/5/text1
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 100001 -> /home/m-b-ashish/Documents/SSY/5/text3
lr-x------ 1 m-b-ashish m-b-ashish 64 Aug 27 10:57 1000010 -> /home/m-b-ashish/Documents/SSY/5/text2
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main() {

    for(;;) {
        //creating 5 files
        int fd1 = open("text1",O_CREAT ,0700 );
        int fd2 = open("text2",O_CREAT ,0700 );
        int fd3 = open("text3",O_CREAT ,0700 );
        int fd4 = open("text4",O_CREAT ,0700 );
        int fd5 = open("text5",O_CREAT ,0700 );

        printf("File Descriptors : %d %d %d %d %d", fd1, fd2, fd3, fd4, fd5);
    }

    return 0;
}