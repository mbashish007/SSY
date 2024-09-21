/*
============================================================================
Name: 32a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 32. Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
                b. protect shared memory from concurrent write access
                c. protect multiple pseudo resources ( may be two) using counting semaphore
                d. remove the created semaphore

Date: 21 September, 2024.
============================================================================

Output
Before entring CS
Inside CS 
Ticket No. current value: 2623 
Ticket value after increment : 2624
Exited CS
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

void semaphore_lock(int semid) {
    struct sembuf sb = {0, -1, 0};  // Decrement semaphore to lock
    if (semop(semid, &sb, 1) == -1) 
        perror("semop (lock)");
}

void semaphore_unlock(int semid) {
    struct sembuf sb = {0, 1, 0};  // Increment semaphore to unlock
    if (semop(semid, &sb, 1) == -1) 
        perror("semop (unlock)");
}

int main(int argc, char * args[]) {
    int fd = open("./tickets", O_RDWR);

     // Step 1: Create a binary semaphore
    key_t key_binary = ftok("./tickets", 'a');  

    int semid_binary = semget(key_binary, 1, 0766);  
    if (semid_binary == -1) {
        perror("semget\n");
        semid_binary = semget(key_binary, 1, IPC_CREAT | 0766);  
        if(semctl(semid_binary, 0, SETVAL, 1)==-1) {
            perror("semget creation\n");
            exit(1);
        }
    }

    

    // struct sembuf sbuf = {0, 1, 0}


    int tic;

    printf("Before entring CS\n");
    semaphore_lock(semid_binary);
    printf("Inside CS \n");
    int rB = read(fd, &tic, sizeof(tic));
    printf("Ticket No. current value: %d \n", tic);
    tic++;

    lseek(fd, 0, SEEK_SET);// always update the first value
    
    int wB = write(fd, &tic, sizeof(tic));
    printf("Ticket value after increment : %d\n", tic);

    if(wB < 0) {
        perror("Write Error");
        return -1;
    }

    sleep(10);
    semaphore_unlock(semid_binary);

    printf("Exited CS\n");
    close(fd);
 return 0;   
}