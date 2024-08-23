#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main() {
	const char *filename = "sample2.txt";

	int fileDescriptor = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	if(fileDescriptor < 0) {
		printf("Error while creating file \n");
		return 0;
	}

	int fileDescriptorDuplicate = fcntl(fileDescriptor, F_DUPFD, 0);
	if(fileDescriptorDuplicate < 0) {
		close(fileDescriptorDuplicate);
		printf("Error while duplicating file \n");
		return 0;
	}

	char *data = "This is written in Original File (fcntl) \n";

	if(write(fileDescriptor, data, strlen(data)) < 0) {
		printf("Error while writing into file \n");
		close(fileDescriptor);
		close(fileDescriptorDuplicate);
		return 0;
	}

	data = "Hello This is written from Duplicate file  (fcntl) \n";

	if(write(fileDescriptorDuplicate, data, strlen(data)) < 0) {
		printf("Error while writing into file \n");
		close(fileDescriptor);
		close(fileDescriptorDuplicate);
		return 0;
	}

	close(fileDescriptor);
	close(fileDescriptorDuplicate);

}