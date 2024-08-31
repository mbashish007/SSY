/*
============================================================================
Name: 30.c 

Author: M B Ashish

Roll No: MT2024085

Description: Q30. Write a program to run a script at a specific time using a Daemon process.

Date: 31 Aug, 2024.
============================================================================

hello.sh
///////////////
#!/bin/bash


echo "Hello World" >> op.txt
////////////////////////

Output
$ ./a.out hello.sh 21 36
Child PID: 4122
Daemon Process is running.....
Shell is running.....


*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>

int should_run_script(int hour, int minute) {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    return local_time->tm_hour == hour && local_time->tm_min == minute;
}

 void run_script(char* script) {
        execl("/bin/sh", script, (char *) NULL);
}
int main(int argc, char* args[]){

    if(argc != 4){
        printf("should pass 4 arguments shell file, targetHour, targetMin\n");
    }
    int targetHour = atoi(args[2]);
    int targetMin = atoi(args[3]);

    if(!fork()){
        printf("Child PID: %d\n",getpid());
        setsid();
        chdir("/");
        umask(0);
        
            while(1){
                sleep(60);
                printf("Daemon Process is running.....\n");

                if (should_run_script(targetHour, targetMin)) {
                    printf("Shell is running.....\n");
                    run_script(args[1]);
                    sleep(1);
                }
            }
    }
    else    
        exit(0);
}