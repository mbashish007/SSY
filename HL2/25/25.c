/*
============================================================================
Name: 25.c 

Author: M B Ashish

Roll No: MT2024085

Description: 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
e. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv

Date: 21 September, 2024.
============================================================================

Output

 Key = 0x80432b1         msgid = 1
a. access permission 744 
b. uid = 1000, gid = 1000
c. time of last message sent: -1533028928 and received: -1533028928
d. time of last change in the message queue: -1533028928
e. size of the queue: 0
f. number of messages in the queue: 0 
g. maximum number of bytes allowed: 16384
h. pid of the msgsnd: 0 and msgrcv: 0
*/

#define _GNU_SOURCE

#include<stdio.h>
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

    struct ipc_perm msg_perm;
    struct msqid_ds mq;

    msgctl(msgid, IPC_STAT, &mq);

    printf("a. access permission %03o \n", mq.msg_perm.mode & 0777);
    printf("b. uid = %d, gid = %d\n", mq.msg_perm.uid, mq.msg_perm.gid);
    printf("c. time of last message sent: %d and received: %d\n",ctime(&mq.msg_stime), ctime(&mq.msg_rtime));
    printf("d. time of last change in the message queue: %d\n", ctime(&mq.msg_ctime));
    printf("e. size of the queue: %ld\n", mq.__msg_cbytes);
    printf("f. number of messages in the queue: %ld \n", mq.msg_qnum);
    printf("g. maximum number of bytes allowed: %ld\n", mq.msg_qbytes);
    printf("h. pid of the msgsnd: %d and msgrcv: %d\n", mq.msg_lspid, mq.msg_lrpid);
    
    return 0;
    
}