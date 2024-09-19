/*
============================================================================
Name: 4.c 

Author: M B Ashish

Roll No: MT2024085

Description: 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

Date: 21 September, 2024.
============================================================================

Output

Time taken = 21296.250000 nano secs
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned long long rdtsc() {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc" : "=A" (dst));

}

int main() {

    double freq = 2.4;
    unsigned long long int start = rdtsc();
    
    for(int i = 0; i< 100; i++)
        getpid();
    
    unsigned long long int end = rdtsc();

    double time = ( end - start)/freq;
    printf("Time taken = %f nano secs\n", time);

    return 0; 
}
    
