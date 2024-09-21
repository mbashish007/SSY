/*
============================================================================
Name: 32d.c 

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
Enter semid
0
semid = 0
Semaphore removed successfully.
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


    int semid;
    printf("Enter semid\n");
    scanf("%d", &semid);   
    printf("semid = %d\n", semid);
   
     if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl remove\n");
        exit(1);
     }

    printf("Semaphore removed successfully.\n");
    

    return 0;
}