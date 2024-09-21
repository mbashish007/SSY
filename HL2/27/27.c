/*
============================================================================
Name: 27.c 

Author: M B Ashish

Roll No: MT2024085

Description: 27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag

Date: 21 September, 2024.
============================================================================

Output
$ ./a.out 
 Key = 0x80432b1         msgid = 1
Msg type = 2 msg = Hello, this is t
No message available at the moment.    

*/

#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/time.h>
#include<time.h>
#include <errno.h>
// #include <cerrno>

// #ifndef MSGBUF_DEFINED
// #define MSGBUF_DEFINED

// struct msgbuf {
//     long mtype;       // Message type
//     char mtext[100];  // Message content
// };

// #endif // MSGBUF_DEFINED

int main() {
    int msgid;
    key_t key;

    key = 0x080432b1;
    msgid = 1;

    if(msgid == -1){
        perror("error\n");
        exit(1);
    }
        
    printf(" Key = 0x%0x\t msgid = %d\n", key, msgid);

   struct msgbuf mbuf;
    // sending msg
    mbuf.mtype = 2;
    strcpy(mbuf.mtext, "Hello, this is type 2 message 1");
    
    if(msgsnd(msgid, &mbuf, sizeof(mbuf), 0) == -1) {
        perror("msgsnd");
        exit(1);
    
    }

    mbuf.mtype = 2;
    strcpy(mbuf.mtext, "Hello, this is type 2 message 2");
    
    if(msgsnd(msgid, &mbuf, sizeof(mbuf), 0) == -1) {
        perror("msgsnd");
        exit(1);
    
    }

    // receive msg
    struct msgbuf receiveBuf;
    if(msgrcv(msgid, &receiveBuf, sizeof(receiveBuf),2, 0) == -1) {
        perror("0 flag\n");

    }
    else {
        printf("Msg type = %ld msg = %s\n", receiveBuf.mtype, receiveBuf.mtext);
    }

    if(msgrcv(msgid, &receiveBuf, sizeof(receiveBuf),1, IPC_NOWAIT) == -1) {
              if (errno == ENOMSG) {
            printf("No message available at the moment.\n");
        } else {
            perror("msgrcv");
        }

    }
    else {
        printf("Msg type = %ld msg = %s\n", receiveBuf.mtype, receiveBuf.mtext);
    }

    return 0;
    
}