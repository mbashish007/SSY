/*
============================================================================
Name: 21a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 21. Write two programs so that both can communicate by FIFO -Use two way communications.

Date: 21 September, 2024.
============================================================================

Output

$ ./p1
Writer program started. Type something to send: 
Write
Hello p2
Read
Received: Hello p1 Nice to meet you
Write

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_path = "myfifo1";  // Path to the FIFO file
    const char *fifo_path1 = "myfifo2";  // Path to the FIFO file
    char buffer1[100];
     char buffer2[100];

    if (mkfifo(fifo_path, 0777) == -1) {
        perror("mkfifo");
    }

     if (mkfifo(fifo_path1, 0777) == -1) {
            perror("mkfifo");
        }


    printf("Writer program started. Type something to send: \n");

    
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

     int fd1 = open(fifo_path, O_RDONLY);
    if (fd1 == -1) {
        perror("open");
        exit(1);
    }

    while (1) {
        // Read input from stdin
        printf("Write\n");
        if (fgets(buffer1, sizeof(buffer1), stdin) != NULL) {
            
            int len = strlen(buffer1); 
            if (write(fd, buffer1, len) == -1) {
                perror("write");
                exit(1);
            }
        }

        printf("Read\n");
        int bytes_read = read(fd1, buffer2, sizeof(buffer2));
        if (bytes_read > 0) {
            printf("Received: %s", buffer2);
        }
    }



    return 0;
}
