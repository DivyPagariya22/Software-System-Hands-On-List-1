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