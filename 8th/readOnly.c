/*
============================================================================
Name : 8.c
Author : Divy Pagariya
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 22th Aug, 2024.
============================================================================
*/





#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
	int fileDescriptor = open("data.txt", O_RDONLY);
	if(fileDescriptor == -1) {
		printf("Error while opening file\n");
		return 0;
	}

	ssize_t byte_read;
	char buffer[BUFFER_SIZE], line[BUFFER_SIZE];

	int j = 0;


	while((byte_read = read(fileDescriptor, buffer, BUFFER_SIZE)) > 0) {
		for(int i = 0; i < byte_read; i++) {
			if(buffer[i] == '\n') {
				line[j] = '\0';

				printf("%s\n", line);
				j = 0;
			} else line[j++] = buffer[i];
		}
	}


	if(j > 0) {
		line[j] = '\0';
		printf("%s\n", line);
	}


	close(fileDescriptor);
	return 0;

}