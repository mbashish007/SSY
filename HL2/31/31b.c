/*
============================================================================
Name: 31b.c 

Author: M B Ashish

Roll No: MT2024085

Description: 31. Write a program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
                b. create a counting semaphore

Date: 21 September, 2024.
============================================================================

Output
Semaphore Id: = 1
Semval before = 4
Semval aftr = 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>


int main() {

    key_t key_counting = ftok(".", 'c');  

    int semid_counting = semget(key_counting, 1, IPC_CREAT | 0666);  // Create semaphore set with 1 semaphore
    if (semid_counting == -1) {
        perror("semget\n");
        exit(1);
    }

    printf("Semaphore Id: = %d\n", semid_counting);
    int semvalbefore = semctl(semid_counting,0, GETVAL);
    printf("Semval before = %d\n", semvalbefore); 

    // Step 2: Initialize the counting semaphore
    if (semctl(semid_counting, 0, SETVAL, 3) == -1) {
        perror("semctl\n");
        exit(1);
    }

     int semval = semctl(semid_counting,0, GETVAL);
    printf("Semval aftr = %d\n", semval); 

 
   
    return 0;
}
