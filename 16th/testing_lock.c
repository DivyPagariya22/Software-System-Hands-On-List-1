/*
============================================================================
Name : 2.c
Author : Divy Pagariya
Description : CWrite a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 22th Aug, 2024.
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

int main() {
	int fd = open("sample.txt", O_RDONLY, 0644);
	set_lock(fd, F_WRLCK);
	
	return 0;

}