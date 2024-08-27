/*
Name: M B Ashish | Roll No: MT2024085
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

Output
$ ./a.out
Enter new file name
f1
File Descriptor Value : 3
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
    char *fname;
    fname = (char *) malloc(255);
    printf("Enter new file name\n");
    scanf("%255s",fname);
    
    int fdesc = creat(fname, 0700);

    if(fdesc == -1) {
        perror("File Creation Error");
        return -1;

    }

    printf("File Descriptor Value : %d", fdesc);
    return 0;
}