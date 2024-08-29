/*
============================================================================
Name : 10.c
Author : Divy Pagariya
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 22th Aug, 2024.
============================================================================
*/




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