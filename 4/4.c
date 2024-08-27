/*
Name: M B Ashish | Roll No: MT2024085

4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Output
$ ./a.out
Enter file name to open with O_RDWR 
f1
 file successfully opened.
Enter file name to open with O_CREAT | O_EXCL 
f1
File Creation Error: File exists
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
    char *fname;
    fname = (char *) malloc(255);

    char *fname2 = (char *) malloc(255);
     printf("Enter file name to open with O_RDWR \n");
    scanf("%255s",fname);

    int fdesc1 = open(fname, O_RDWR);
    if(fdesc1 == -1) {
        perror("File Opening error: ");
        return -1;

    }
    else {
        printf("%s file successfully opened.\n", fname2);
    }
    
    printf("Enter file name to open with O_CREAT | O_EXCL \n");
    scanf("%255s",fname2);
    
    int fdesc = open(fname,O_CREAT | O_EXCL ,0700 );
 
    if(fdesc == -1) {
        perror("File Creation Error");
        return -1;

    }

    printf("File Descriptor Value : %d", fdesc);
    return 0;
}