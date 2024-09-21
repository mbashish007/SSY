/*
============================================================================
Name: 24.c 

Author: M B Ashish

Roll No: MT2024085

Description: 24. Write a program to create a message queue and print the key and message queue id.

Date: 21 September, 2024.
============================================================================

Output

 Key = 0x40435dd         msgid = 0
*/

#define _GNU_SOURCE

#include<stdio.h>
#include<sys/msg.h>


int main() {
    int msgid;
    key_t key;

    key = ftok(".", "a");
    msgid = msgget(key, IPC_CREAT|IPC_EXCL|0744);

    printf(" Key = 0x%0x\t msgid = %d\n", key, msgid);
    
}