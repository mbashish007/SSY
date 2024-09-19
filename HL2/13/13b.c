/*
============================================================================
Name: 13a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 21 September, 2024.
============================================================================

Output

$$ ./13b 
Program started

============================================================================
*/

#define _POSIX_C_SOURCE 200112L   // Enable POSIX features

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>




int main(int argc, char* argv) {
    printf("Program started\n");
    // int pid = 

    pid_t pid = 97988;
    kill(pid, SIGSTOP); 
    return 0;
}