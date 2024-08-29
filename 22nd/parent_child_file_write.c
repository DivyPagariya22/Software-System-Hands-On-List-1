/*
============================================================================
Name : 22.c
Author : Divy Pagariya
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("Error opening file");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == -1) {
    	printf("Error while creating child processes \n");
    	return 0;
    } else if(pid == 0) {
    	const char *child_msg = "Hello from the child process.\n";
        if (write(fd, child_msg, strlen(child_msg)) < 0) {
            printf("Error writing from child process \n");
            close(fd);
            exit(1);
        }
        printf("Child process wrote to the file.\n");
    } else {
    	const char *parent_msg = "Hello from the parent process.\n";
        if (write(fd, parent_msg, strlen(parent_msg)) < 0) {
            printf("Error writing from child process \n");
            close(fd);
            exit(1);
        }
        printf("Parent process wrote to the file.\n");
    }


    close(fd);
    return 0;

}