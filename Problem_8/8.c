/*
Name: M B Ashish | Roll No: MT2024085

8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.

Output
$ cat f1
Hello
Ashish
Welcome Aboard

 ./a.out f1
Hello
Ashish
Welcome Aboard
*/


#include<stdio.h>
#include<unistd.h>

const char EOL = '\n';
int main(int argc, char* args[]) {
    FILE *fd = fopen(args[1], "r");
    if(fd == NULL) {
        perror("Program");
        exit(0);
    }
        int c = fgetc(fd);
        char buffer[1024];
        int k=0;

        while(c != EOF) {
        while(c!=EOL){
            buffer[k] = c;
            k++;
            // printf("%c", c);
            c = fgetc(fd);
        } 
        // c = 0;

        buffer[k++] = '\n';
        write(1, buffer, k);
        k =0;
        buffer[0] = '\0';
           c =  fgetc(fd);    
        }

        fclose(fd);
        
    }

