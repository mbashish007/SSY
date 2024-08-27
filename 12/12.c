/*
Name: M B Ashish | Roll No: MT2024085

12. Write a program to find out the opening mode of a file. Use fcntl.

Output

$ ./a.out f4
status type : 32768 
Opening mode : O_RDONLY
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * args[]) {

    int fd = open("f2", O_RDONLY | O_CREAT, 0700 );

    if(fd == -1) {
        perror("File Opening Error.");
    }

    int fstatustype = fcntl(fd, F_GETFL);

    printf("status type : %d \n", fstatustype);

    switch (O_ACCMODE &fstatustype)
    {
    case O_RDONLY: printf("Opening mode : O_RDONLY");
        break;

    case O_WRONLY: printf("Opening mode : O_WRONLY");
        break;

    case O_RDWR: printf("Opening mode : O_RDWR");
        break;

    case O_APPEND: printf("Opening mode : O_APPEND");
        break;
    
    case O_CREAT: printf("Opening mode : O_CREAT");
        break;

    case O_TRUNC: printf("Opening mode : O_TRUNC");
        break;
  
   case (O_RDWR | O_CREAT): printf("Opening mode : O_TRUNC");
        break;

    }

}

