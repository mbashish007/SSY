/*
============================================================================
Name: 31a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 31. Write a program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
                b. create a counting semaphore

Date: 21 September, 2024.
============================================================================

Output
binary semaphore created with id: 0
Semval before = 1
Semval aftr = 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>


int main() {
    // Step 1: Create a binary semaphore
    key_t key_binary = ftok(".", 'a');  

    int semid_binary = semget(key_binary, 1, IPC_CREAT | 0766);  
    if (semid_binary == -1) {
        perror("semget\n");
        exit(1);
    }
    printf("binary semaphore created with id: %d\n", semid_binary);
    int semvalbefore = semctl(semid_binary,0, GETVAL);
    printf("Semval before = %d\n", semvalbefore); 

    // Step 2: Initialize the binary semaphore to 1
    if (semctl(semid_binary, 0, SETVAL, 0) == -1) {
        perror("semctl\n");
        exit(1);
    }

    int semval = semctl(semid_binary,0, GETVAL);
    printf("Semval aftr = %d\n", semval); 


   
    return 0;
}
