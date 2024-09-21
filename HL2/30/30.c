/*
============================================================================
Name: 30.c 

Author: M B Ashish

Roll No: MT2024085

Description: 30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory

Date: 21 September, 2024.
============================================================================

Output
Shared Memory ID: 294923
Written to shared memory: Writing by T1
Shared memory ptr detached successfully.
Shared memory removed successfully.
*/

#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define SHM_SIZE 1024  // Size of the shared memory

int main() {
    // Create shared memory
    key_t key = ftok(".", 'a');  
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0744);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    printf("Shared Memory ID: %d\n", shmid);

    // a. Write data to shared memory
    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    strncpy(data, "Writing by T1", SHM_SIZE);
    data = (char *)shmat(shmid, NULL, 0);
    printf("Written to shared memory: %s\n", data);


   // b. Attach with O_RDONLY
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Attempt to print the data
    printf("Data in shared memory: %s\n", data);



    // c. Detach from shared memory
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    printf("Shared memory ptr detached successfully.\n");

    // d. Remove the shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}
