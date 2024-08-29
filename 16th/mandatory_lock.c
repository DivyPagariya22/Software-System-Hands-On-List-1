/*
============================================================================
Name : 16.c
Author : Divy Pagariya
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
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
	const char *filename = "sample.txt";

	int fileDescriptor = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if(fileDescriptor == -1) {
		printf("Error while opening file \n");
		return 0;
	}

	printf("Applying write lock...\n");
	set_lock(fileDescriptor, F_WRLCK);
	printf("Write lock applied. Press Enter to release the lock...\n");
	getchar();

	
	remove_lock(fileDescriptor);
	printf("Write lock released. Press Enter to apply read lock...\n");
	getchar();


	printf("Applying read lock...\n");
    set_lock(fileDescriptor, F_RDLCK);
    printf("Read lock applied. Press Enter to release the lock...\n");
    getchar();


    remove_lock(fileDescriptor);

    printf("Read lock released\n");


    close(fileDescriptor);
    return 0;

}