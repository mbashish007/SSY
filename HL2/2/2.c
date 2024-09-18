/*
============================================================================
Name: 2.c 

Author: M B Ashish

Roll No: MT2024085

Description: 2. Write a program to print the system resource limits. Use getrlimit system call.


Date: 21 September, 2024.
============================================================================

Output

RLIMIT_AS: soft limit = -1 : hard limit = -1 
RLIMIT_CORE: soft limit = 0 : hard limit = -1 
RLIMIT_CPU: soft limit = -1 : hard limit = -1 
RLIMIT_DATA: soft limit = -1 : hard limit = -1 
RLIMIT_FSIZE: soft limit = -1 : hard limit = -1 
RLIMIT_LOCKS: soft limit = -1 : hard limit = -1 
RLIMIT_MEMLOCK: soft limit = 1007763456 : hard limit = 1007763456 
Note: RLIM_INFINITY = -1
*/

#include <sys/resource.h>
#include <stdio.h>


int main() {

    struct  rlimit lim;

    int syslim = getrlimit(RLIMIT_AS, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");

  
    
    printf("RLIMIT_AS: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);

    syslim = getrlimit(RLIMIT_CORE, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");

    printf("RLIMIT_CORE: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);
    
    syslim = getrlimit(RLIMIT_CPU, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");
    
    printf("RLIMIT_CPU: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);
    
    syslim = getrlimit(RLIMIT_DATA, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");
    
    printf("RLIMIT_DATA: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);
    
    syslim = getrlimit(RLIMIT_FSIZE, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");
    
    printf("RLIMIT_FSIZE: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);

    syslim = getrlimit(RLIMIT_LOCKS, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n"); 
    
    printf("RLIMIT_LOCKS: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);
    
    syslim = getrlimit(RLIMIT_MEMLOCK, &lim);

    if(syslim == -1)
        perror("Getrlimit error\n");
    
    printf("RLIMIT_MEMLOCK: soft limit = %ld : hard limit = %ld \n", lim.rlim_cur, lim.rlim_max);

    printf("Note: RLIM_INFINITY = %ld\n",RLIM_INFINITY);
    
}
    
