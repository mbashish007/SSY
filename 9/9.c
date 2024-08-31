/*


============================================================================
Name: 9.c 
Author: M B Ashish 
Roll No: MT2024085

Description: Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 31 Aug, 2024.
============================================================================

Output

$ ./a.out file1

File: file1
Inode: 1057799
No. of Hard links: 1
UID: 1000
GID: 1000
Size: 23 bytes
Block Size: 4096 bytes
No. of Blocks: 8
Last Access Time: Tue Aug 27 15:27:36 2024
Last Modification Time: Tue Aug 27 15:27:49 2024
Last Status Change Time: Tue Aug 27 15:27:49 2024

*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char * args[]) {
    struct  stat stats;

    if(stat("file1", &stats) == -1) {
        perror("Stat error");
        return -1;
    }

       printf("\nFile: %s\n", args[1]);
    printf("Inode: %ld\n",(long)stats.st_ino);
    printf("No. of Hard links: %ld\n", (long)stats.st_nlink);
    printf("UID: %d\n", stats.st_uid);
    printf("GID: %d\n", stats.st_gid);
    printf("Size: %ld bytes\n", (long)stats.st_size);
    printf("Block Size: %ld bytes\n", (long)stats.st_blksize);
    printf("No. of Blocks: %ld\n",(long) stats.st_blocks);
    printf("Last Access Time: %s", ctime(&stats.st_atime));
    printf("Last Modification Time: %s", ctime(&stats.st_mtime));
    printf("Last Status Change Time: %s\n", ctime(&stats.st_ctime));
}