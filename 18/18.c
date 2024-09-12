/*

============================================================================
Name: 18.c
Author: M B Ashish 
Roll No: MT2024085

Description: 18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

Date: 31 Aug, 2024.
============================================================================
Output

$ cat records 
Hello
World
C Programming


$ ./a.out records
Select option
Read Record: press 1
Modify Record: press 2
1
Select record to read
1 | 2 | 3 
2
Acquiring Read Lock
option = 2
calc offset = 20offset = 20 
Record = World
 
Released read lock
Select option
Read Record: press 1
Modify Record: press 2
2
Select record to modify
1 | 2 | 3 
2
Enter modified data
universe
buffer = universe
Acquiring Write Lock
Record = Updated Successfully 
Released write lock
Select option
Read Record: press 1
Modify Record: press 2
^C

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define recSize 20

void readRecord(int fd) {
    struct flock lock;
    
    printf("Select record to read\n");
    printf("1 | 2 | 3 \n");
    int op;
    scanf("%d", &op);

    lock.l_type=F_RDLCK;
    lock.l_whence= SEEK_SET;
    lock.l_start=(recSize *(op- 1));
    lock.l_len = recSize;
    lock.l_pid = getpid();

    char buffer[recSize];
    printf("Acquiring Read Lock\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("option = %d\n",op);
    int offset = lseek(fd,(recSize *(op-1)), SEEK_SET);
    int rB = read(fd, &buffer, recSize);
    if(rB == -1) {
        perror("read error\n");
        return;
    }
    printf("Record = %s \n", buffer);
    char a[5];
    scanf("%s",a);
    lock.l_type= F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Released read lock\n");


}

void modifyRecord(int fd) {
    struct flock lock;
    int option ;
    printf("Select record to modify\n");
    printf("1 | 2 | 3 \n");
    scanf("%d", &option);

    lock.l_type=F_WRLCK;
    lock.l_whence= SEEK_SET;
    lock.l_start=(recSize *(option- 1));
    lock.l_len = recSize;
    lock.l_pid = getpid();

    char buffer[recSize];
    printf("Enter modified data\n");
    scanf("%s", buffer);
    buffer[recSize-1] = '\n';
    printf("buffer = %s \n", buffer);

    printf("Acquiring Write Lock\n");
    fcntl(fd, F_SETLKW, &lock);
    lseek(fd,(recSize *(option- 1)), SEEK_SET);
   
    int rB = write(fd, &buffer, recSize);

    if(rB == -1) {
        perror("write error\n");
        return;
    }
    

    printf("Record = Updated Successfully \n");
    char a[5];
    scanf("%s",a);
    lock.l_type= F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Released write lock\n");


}


int main(int argc, char * args[]) {

    
    int fd ;
    fd = open(args[1], O_RDWR);
    
    if(fd == -1) {
        fd = open(args[1], O_RDWR | O_CREAT, 0700) ;
            if(fd == -1) {
                perror("File Creation Error\n");
                return -1;
            }

           char recs[3][20] = {
        "Hello\n",
        "World\n",
        "C Programming\n"
    };

        int wB = write(fd, recs, 3*recSize);
        if(wB == -1) {
            perror("Write Error");
            return -1;
        }       
    }

    

    while(1) {
        printf("Select option\n");
        printf("Read Record: press 1\n");
        printf("Modify Record: press 2\n");
        // printf("Quit anything else\n");
        int option ;
        scanf("%d", &option);

        if(option == 1) 
            readRecord(fd);
        else if(option == 2)
            modifyRecord(fd);
        
        // else return 0;


    }

    return 0;

}
