/*
============================================================================
Name: 5.c 

Author: M B Ashish

Roll No: MT2024085

Description: 6. Write a simple program to create three threads.

Date: 21 September, 2024.
============================================================================

Output

Thread 2 is running
Thread 1 is running
Thread 3 is running
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