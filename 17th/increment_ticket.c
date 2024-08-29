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

void set_lock(int fd, int lock_type) {
    struct flock lock;

    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    if(fcntl(fd, F_SETLKW, &lock) == -1) {
        printf("Unable to lock \n");
        exit(EXIT_FAILURE);
    }
}

void remove_lock(int fd) {
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    if(fcntl(fd, F_SETLKW, &lock) == -1) {
        printf("Unable to release lock \n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *filename = "ticket.txt";
    int fd;
    int ticket_number;

    
    fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Error while opening file \n");
        return 0;
    }

    set_lock(fd, F_WRLCK);
    printf("Write lock acquired. Reading and updating ticket number...\n");

    // Read the ticket number from the file
    if (read(fd, &ticket_number, sizeof(ticket_number)) == -1) {
        printf("Error while putting lock \n");
        remove_lock(fd);
        close(fd);
        return 0;
    }

    // Increment the ticket number
    ticket_number++;

    // Move the file pointer back to the beginning of the file
    if (lseek(fd, 0, SEEK_SET) == -1) {
        printf("Error while moving pointer in file \n");
        remove_lock(fd);
        close(fd);
        return 0;
    }

    // Write the new ticket number back to the file
    if (write(fd, &ticket_number, sizeof(ticket_number)) == -1) {
        printf("Error while writing ticket in file \n");
        remove_lock(fd);
        close(fd);
        return 0;
    }

    printf("New ticket number %d written to file.\n", ticket_number);

    // Release the write lock
    remove_lock(fd);
    printf("Write lock released.\n");

    // Close the file
    close(fd);
    return 0;
}
