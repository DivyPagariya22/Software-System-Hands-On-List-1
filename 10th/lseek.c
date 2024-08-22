#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>


int main() {
	const char *filename = "sample.txt";

	int fileDescriptor = open(filename, O_RDWR | O_CREAT, 0644);
	if(fileDescriptor < 0) {
		printf("Error while creating file \n");
		close(fileDescriptor);
		return 0;
	}

	const char *text = "abcdefghij";

	ssize_t byte_written = write(fileDescriptor, text, strlen(text));

	if(byte_written < 0) {
		printf("Error while writing in file \n");
		close(fileDescriptor);
		return 0;
	}

	off_t offset = lseek(fileDescriptor, strlen(text), SEEK_CUR);

	if(offset == (off_t) -1) {
		printf("Error while moving pointer in file \n");
		close(fileDescriptor);
		return 0;
	}

	text = "1234567890";
	byte_written = write(fileDescriptor, text, strlen(text));

	if(byte_written < 0) {
		printf("Error while writing in file after seeking \n");
		close(fileDescriptor);
		return 0;
	}

	close(fileDescriptor);

	printf("File written successfully. Check the file with `od -c %s` to see the empty spaces.\n", filename);

	return 0;


}