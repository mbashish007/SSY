/*
============================================================================
Name: 28.c 

Author: M B Ashish

Roll No: MT2024085

Description: 28. Write a program to change the existing message queue permission. (use msqid_ds structure)

Date: 21 September, 2024.
============================================================================

Output
 Key = 0x40435dd         msgid = 0
Accessed Message Queue ID: 0
Current permissions: 744
Permissions changed to: 644

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

    key = 0x040435dd;

    msgid = msgget(key, 0666); 
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    printf(" Key = 0x%0x\t msgid = %d\n", key, msgid);

    printf("Accessed Message Queue ID: %d\n", msgid);

    
    struct msqid_ds mq;

    // Get the current attributes of the message queue
    if (msgctl(msgid, IPC_STAT, &mq) == -1) {
        perror("msgctl");
        exit(1);
    }

  
    printf("Current permissions: %o\n", mq.msg_perm.mode & 0777);

    // Change the permission
    mq.msg_perm.mode = 0644;  

    // Set the new attributes
    if (msgctl(msgid, IPC_SET, &mq) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Permissions changed to: %o\n", mq.msg_perm.mode & 0777);


    return 0;
    
}