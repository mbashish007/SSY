/*

============================================================================
Name: 19.c
Author: M B Ashish 
Roll No: MT2024085

Description: 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.

============================================================================
$ sudo dmidecode -t processor | grep Speed
        Max Speed: 4200 MHz
        Current Speed: 2400 MHz

Output
$./a.out 
Time taken = 3725.000000 nano secs
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
    getpid();
    unsigned long long int end = rdtsc();

    double time = ( end - start)/freq;
    printf("Time taken = %f nano secs", time);

    return 0;

}