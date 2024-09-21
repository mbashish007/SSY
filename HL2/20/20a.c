/*
============================================================================
Name: 20a.c 

Author: M B Ashish

Roll No: MT2024085

Description: 20. Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 21 September, 2024.
============================================================================

Output
mkfifo: File exists
Writer program started. Type something to send: 
hello
popopo

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
    char buffer[100];

    if (mkfifo(fifo_path, 0777) == -1) {
        perror("mkfifo");
    }

    printf("Writer program started. Type something to send: \n");

    
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    while (1) {
        // Read input from stdin
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            
            int len = strlen(buffer); 
            if (write(fd, buffer, len) == -1) {
                perror("write");
                exit(1);
            }
        }
    }



    return 0;
}
