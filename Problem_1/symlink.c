#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {
    printf("Hello world\n");

    char target[256];
    char symlink_st[256];

    printf("Enter target path \n");
    scanf("%s", target);
    printf("Enter symlink path \n");
    scanf("%s", symlink_st);

    if(symlink(target, symlink_st) == 0) {
        printf("Symlink created");
    }
    else perror("Symlink error");
} 