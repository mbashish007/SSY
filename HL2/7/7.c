/*
============================================================================
Name: 7.c 

Author: M B Ashish

Roll No: MT2024085

Description: 7. Write a simple program to print the created thread ids.

Date: 21 September, 2024.
============================================================================

Output

Thread Id: 140470378292928 is running with arg = 2
Thread Id: 140470386685632 is running with arg = 1
Thread Id: 140470369900224 is running with arg = 3
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

// Function that each thread will run
void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    long long int tid = pthread_self();
    printf("Thread Id: %lld is running with arg = %d\n", tid, thread_num);
    return NULL;
}

int main() {
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    int arg1 = 1;
    int arg2 = 2;
    int arg3 = 3;

    if(pthread_create(&t1, NULL, thread_function, &arg1 )!=0)
        perror("Thread Creation Error\n");
    
    if(pthread_create(&t2, NULL, thread_function, &arg2 )!=0)
        perror("Thread Creation Error\n");

    if(pthread_create(&t3, NULL, thread_function, &arg3 )!=0)
        perror("Thread Creation Error\n");
    // Wait for all threads to finish
        if (pthread_join(t1, NULL) != 0) {
                    perror("Failed to join thread");
                    return 1;
                }

        if (pthread_join(t2, NULL) != 0) {
                    perror("Failed to join thread");
                    return 1;
                }

        if (pthread_join(t3, NULL) != 0) {
                    perror("Failed to join thread");
                    return 1;
                }

    return 0;
}