/*
============================================================================
Name: 9.c 

Author: M B Ashish

Roll No: MT2024085

Description: 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

Date: 21 September, 2024.
============================================================================

Output

Program started
SIGINT will be ignored
Hello
^CSIGINT reverted to default behaviour 
^C

============================================================================
*/

#include <stdio.h>
#include<signal.h>
#include<unistd.h>


int main() {
    printf("Program started\n");

    printf("SIGINT will be ignored\n");
    signal(SIGINT,SIG_IGN);
    // pause();
    printf("Hello\n");
    for(int i = 0; i< 1000000000; i++){
        // if(i%10000 == 0) printf(" waiting \n");
    }

    printf("SIGINT reverted to default behaviour \n");
    signal(SIGINT,SIG_DFL);
    pause();    
    
    
    return 0;
}