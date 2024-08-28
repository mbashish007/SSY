/*
Name: M B Ashish | Roll No: MT2024085

14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

Output
$ ./a.out d1
File type:                directory

$ ./a.out f1
File type:                regular file
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* args[]) {
      struct stat sb;

    if (stat(args[1], &sb) == -1) {
            perror("stat");
            return -1;
        }

      printf("File type:                ");

      if(S_ISBLK(sb.st_mode)) 
        printf("block device\n"); 
      else if(S_ISCHR(sb.st_mode)) printf("character device\n"); 
      else if(S_ISDIR(sb.st_mode))  printf("directory\n");  
      else if(S_ISFIFO(sb.st_mode)) printf("FIFO/pipe\n");  
      else if(S_ISLNK(sb.st_mode))  printf("symlink\n");  
      else if(S_ISREG(sb.st_mode)) printf("regular file\n");   
      else if(S_ISSOCK(sb.st_mode)) printf("socket\n");     
      else  printf("unknown?\n"); 


}