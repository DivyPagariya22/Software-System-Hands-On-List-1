/*
============================================================================
Name : 3.c
Author : Divy Pagariya
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 22th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main() {

	int fileDescriptor = creat("newFile.txt", 0644);

	if(fileDescriptor == -1) {
		printf("Error while creating file \n");
		return 0;
	}

	printf("Value of File Descriptor = %d \n", fileDescriptor);

	close(fileDescriptor);
	return 0;
	
}