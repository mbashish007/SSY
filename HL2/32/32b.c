/*
============================================================================
Name: 32b.c 

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
key = 0x62043708 semid = 4
shmid = 458771
Before entring CS
Inside CS 
Earlier data = Hello

Enter new data
Hi
Writing to shared memory...
Exited CS
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

     // Step 1: Create a binary semaphore
    key_t key_binary = ftok(".", 'b');  

    int semid_binary = semget(key_binary, 1, 0766);  
    if (semid_binary == -1) {
        perror("semget\n");
        semid_binary = semget(key_binary, 1, IPC_CREAT | 0766);  
        if(semctl(semid_binary, 0, SETVAL, 1)==-1) {
            perror("semget creation\n");
            exit(1);
        }
    }

    printf("key = 0x%0x semid = %d\n", key_binary, semid_binary);

    int shmid = shmget(key_binary, SHM_SIZE,  0666);
    if (shmid == -1){
        perror("shmget\n");
        shmid = shmget(key_binary, SHM_SIZE, IPC_CREAT | 0666);
    }
    printf("shmid = %d\n", shmid);

    // Step 3: Attach to the shared memory
    char *data = (char *)shmat(shmid, (void *)0, 0);
    if (data == (char *)(-1)) {
        perror("shmat\n");
        exit(1);
    }

    // Step 4: Write data to shared memory (protected)
    printf("Before entring CS\n");
    semaphore_lock(semid_binary);  
    printf("Inside CS \n");
    printf("Earlier data = %s\n", data);
    printf("Enter new data\n");
    char buff[100];
    if (fgets(buff, sizeof(buff), stdin) == NULL) {
        perror("fgets\n");
        exit(1);
    }
    printf("Writing to shared memory...\n");
    strncpy(data, buff, SHM_SIZE);
    sleep(10);
    semaphore_unlock(semid_binary);  
    printf("Exiting CS\n");
    // Detach shared memory
    if (shmdt(data) == -1) 
    {
        perror("shmdt\n");
        exit(1);
    }

    

   
 return 0;   
}