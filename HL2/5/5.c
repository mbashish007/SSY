/*
============================================================================
Name: 5.c 

Author: M B Ashish

Roll No: MT2024085

Description: 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 21 September, 2024.
============================================================================

Output

a. maximum length of the arguments to the exec family of functions = 2097152.
b. maximum number of simultaneous process per user id. = 30461.
c. number of clock ticks (jiffy) per second = 100.
d. maximum number of open files. = 1048576.
e. size of a page = 4096.
f. total number of pages in the physical memory = 1968296.
g. number of currently available pages in the physical memory. = 577576.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
long argMax = sysconf(_SC_ARG_MAX);
errno = 0;
if(errno)
perror("sysconf\n");

printf("a. maximum length of the arguments to the exec family of functions = %ld.\n", argMax);

long CHILD_MAX = sysconf(_SC_CHILD_MAX);
if(errno)
perror("sysconf\n");
printf("b. maximum number of simultaneous process per user id. = %ld.\n", CHILD_MAX);

long ticks = sysconf(_SC_CLK_TCK);
if(errno)
perror("sysconf\n");
printf("c. number of clock ticks (jiffy) per second = %ld.\n", ticks);

long OPEN_MAX = sysconf(_SC_OPEN_MAX);
if(errno)
perror("sysconf\n");
printf("d. maximum number of open files. = %ld.\n", OPEN_MAX);

long PAGE_SIZE = sysconf(_SC_PAGE_SIZE);
if(errno)
perror("sysconf\n");
printf("e. size of a page = %ld.\n", PAGE_SIZE);

long PHYS_PAGES = sysconf(_SC_PHYS_PAGES);
if(errno)
perror("sysconf\n");
printf("f. total number of pages in the physical memory = %ld.\n", PHYS_PAGES);

long AVPHYS_PAGES = sysconf(_SC_AVPHYS_PAGES);
if(errno)
perror("sysconf\n");
printf("g. number of currently available pages in the physical memory. = %ld.\n", AVPHYS_PAGES);

}