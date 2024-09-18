/*
============================================================================
Name: 3.c 

Author: M B Ashish

Roll No: MT2024085

Description: 3. Write a program to set (any one) system resource limit. Use setrlimit system call.


Date: 21 September, 2024.
============================================================================

Output

Before setrlimit; RLIMIT_FSIZE: soft limit = -1 : hard limit = -1 
After setrlimit; RLIMIT_FSIZE: soft limit = 500 : hard limit = -1 
Note: RLIM_INFINITY = -1
*/

#include <sys/resource.h>
#include <stdio.h>


int main() {

    struct  rlimit lim;
    struct  rlimit lim1;
    
    int syslim = getrlimit(RLIMIT_FSIZE, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");
    
    printf("Before setrlimit; RLIMIT_FSIZE: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);

    lim.rlim_cur = 500;

    syslim = setrlimit(RLIMIT_FSIZE, &lim);
    
    if(syslim == -1)
            perror("Setrlimit error\n");

    syslim = getrlimit(RLIMIT_FSIZE, &lim1);

    if(syslim == -1)
        perror("Getrlimit error\n");
    
    printf("After setrlimit; RLIMIT_FSIZE: soft limit = %ld : hard limit = %ld \n", lim1.rlim_cur, lim1.rlim_max);

    printf("Note: RLIM_INFINITY = %ld\n",RLIM_INFINITY);
    
}
    
