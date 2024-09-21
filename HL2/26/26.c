/*
============================================================================
Name: 26.c 

Author: M B Ashish

Roll No: MT2024085

Description: 26. Write a program to send messages to the message queue. Check $ipcs -q

Date: 21 September, 2024.
============================================================================

Output
$ ./a.out 
 Key = 0x404362b         msgid = 2
 
$ ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x040435dd 0          m-b-ashish 744        0            0           
0x080432b1 1          m-b-ashish 744        0            0           
0x0404362b 2          m-b-ashish 744        112          1           

*/

#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/time.h>
#include<time.h>

int main() {
    int msgid;
    key_t key;

    key = ftok(".", "a");
    msgid = msgget(key, IPC_CREAT|0744);

    if(msgid == -1){
        perror("error\n");
        exit(1);
    }
        
    printf(" Key = 0x%0x\t msgid = %d\n", key, msgid);

    struct msgbuf {
    long int mtype;       // Message type
    char mtext[100];  // Message content
    } mbuf;

    mbuf.mtype = 2;
    strcpy(mbuf.mtext, "Hello, this is type 2 message");
    
    if(msgsnd(msgid, &mbuf, sizeof(mbuf), 0) == -1) {
        perror("msgsnd");
        exit(1);
    
    }

    return 0;
    
}