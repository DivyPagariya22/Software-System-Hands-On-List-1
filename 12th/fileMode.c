/*
============================================================================
Name : 12.c
Author : Divy Pagariya
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 23th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_open_mode(int flags) {
    int access_mode = flags & O_ACCMODE;  

    if (access_mode == O_RDONLY) {
        printf("read-only mode.\n");
    } else if (access_mode == O_WRONLY) {
        printf("write-only mode.\n");
    } else if (access_mode == O_RDWR) {
        printf("read-write mode.\n");
    } else {
        printf("Unknown mode.\n");
    }
}

int main() {
    const char *filename = "sample.txt"; 

   
    int fd = open(filename, O_RDONLY | O_CREAT, 0644);
    if (fd < 0) {
        printf("Cant create or open file \n");
        return 0;
    }

    
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        printf("Error while getting flags \n");
        close(fd);
        return 0;
    }

    
    print_open_mode(flags);

    close(fd);  

    return 0;
}
