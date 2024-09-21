/*
============================================================================
Name: 32c.c 

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
semid = 5
semval = 1
Before entering CS
Using one resource (resource lock acquired)
Resource released
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(1);
}

void semaphore_lock(int semid) {
    struct sembuf sb = {0, -1, 0};  
    if (semop(semid, &sb, 1) == -1) 
        handle_error("semop (lock)");
}

void semaphore_unlock(int semid) {
    struct sembuf sb = {0, 1, 0};  
    if (semop(semid, &sb, 1) == -1) 
        handle_error("semop (unlock)");
}

int main() {

    key_t key = ftok(".", 'R');


    int semid = semget(key, 1, 0766);
    if (semid == -1) {
        semid = semget(key, 1, IPC_CREAT | 0766);
           // Initialize counting semaphore to 2 (for two resources)
         if (semctl(semid, 0, SETVAL, 2) == -1) handle_error("semctl");
    }
    
    printf("semid = %d\n", semid);
   
        printf("semval = %d\n", semctl(semid, 0, GETVAL));
        printf("Before entering CS\n");
        semaphore_lock(semid);  
        printf("Using one resource (resource lock acquired)\n");
        sleep(30);  

        semaphore_unlock(semid);  
        printf("Resource released\n");

    

    return 0;
}