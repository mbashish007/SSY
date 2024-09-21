/*
============================================================================
Name: 29.c 

Author: M B Ashish

Roll No: MT2024085

Description: 29. Write a program to remove the message queue.
Date: 21 September, 2024.
============================================================================

Output
 Key = 0x404362b         msgid = 2
Current permissions: 744
Message Queue ID 2 removed successfully.

*/

#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/time.h>
#include<time.h>
#include <errno.h>

int main() {
    int msgid;
    key_t key;

    key = 0x0404362b;

    msgid = msgget(key, 0744); 
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    printf(" Key = 0x%0x\t msgid = %d\n", key, msgid);

 
    
    struct msqid_ds mq;

    // Get the current attributes of the message queue
    if (msgctl(msgid, IPC_STAT, &mq) == -1) {
        perror("msgctl");
        exit(1);
    }

  
    printf("Current permissions: %o\n", mq.msg_perm.mode & 0777);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {//Delete mq
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue ID %d removed successfully.\n", msgid);



    return 0;
    
}