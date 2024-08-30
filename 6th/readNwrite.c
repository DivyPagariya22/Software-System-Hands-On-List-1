/*
============================================================================
Name : 6.c
Author : Divy Pagariya
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 22th Aug, 2024.
============================================================================
*/





#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main() {

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    
    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    return 0;
}
