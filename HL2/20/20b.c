/*
============================================================================
Name: 20b.c 

Author: M B Ashish

Roll No: MT2024085

Description: 20. Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 21 September, 2024.
============================================================================

Output
Reader program started. Waiting for data...
Received: hello
Received: popopo

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "myfifo1";  // Path to the FIFO file
    char buffer[100];

    // Open the FIFO for reading
    int fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Reader program started. Waiting for data...\n");

    // Read from the FIFO
    while (1) {
        int bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            printf("Received: %s", buffer);
        }
    }

 
    return 0;
}
