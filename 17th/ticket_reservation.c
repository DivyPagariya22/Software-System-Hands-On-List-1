/*
============================================================================
Name : 17.c
Author : Divy Pagariya
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 23th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *filename = "ticket.txt";
    int fd;
    int initial_ticket_number = 1000; 

    
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR, 0644);
    if (fd == -1) {
        printf("Error while opening file \n");
        return 0;
    }

    if (write(fd, &initial_ticket_number, sizeof(initial_ticket_number)) == -1) {
        printf("Erroe while writing ticket number in file \n");
        close(fd);
        return 0;
    }

    printf("Initial ticket number %d written to file.\n", initial_ticket_number);

    
    close(fd);
    return 0;
}
