#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>

int main() {
	fd_set read_fds;

	struct timeval timeout;

	timeout.tv_sec = 10;
	timeout.tv_usec = 0;


	FD_ZERO(&read_fds);

	FD_SET(STDIN_FILENO, &read_fds);

	printf("Waiting for input for 10 second \n");


	int val = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);


	if(val == -1) {
		printf("Error while reading input \n");
		return 0;
	}

	if(val == 0) {
		printf("No Data was entered in 10 second \n");
		return 0;
	}

	if(FD_ISSET(STDIN_FILENO, &read_fds)) {
		char buffer[1024];

		printf("Data is available on STDIN \n");

		ssize_t byte_read = read(STDIN_FILENO, buffer, 1024);

		buffer[byte_read] = '\0';


		printf("Data = %s\n", buffer);
	}

	return 0;
}