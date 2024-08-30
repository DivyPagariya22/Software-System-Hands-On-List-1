/*
============================================================================
Name : 7.c
Author : Divy Pagariya
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 22th Aug, 2024.
============================================================================
*/





#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main() {
	int fd_source, fd_dest;

	ssize_t byteRead, byteWritten;

	char buffer[BUFFER_SIZE];

	
	fd_source = open("file_a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if(fd_source == -1) printf("Error while creating file \n");
	else printf("Succesfully Created file_a.txt\n");

	const char *content = "This is File A content which we will copy in File B \n";

	write(fd_source, content, strlen(content));

	close(fd_source);



	

	fd_source = open("file_a.txt", O_RDONLY);

	if(fd_source == -1) printf("Error while opening file \n");
	else printf("Succesfully opened file_a.txt\n");

	fd_dest = open("file_b.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd_dest == -1) printf("Error while creating file \n");
	else printf("Succesfully Created file_b.txt\n");


	while((byteRead = read(fd_source, buffer, BUFFER_SIZE)) > 0){

		byteWritten = write(fd_dest, buffer, byteRead);

		if(byteRead != byteWritten) {
			printf("Error while writing to destination file \n");
			close(fd_source);
			close(fd_dest);
		}
	}

	if(byteRead == -1) printf("Error \n");
	close(fd_source);
	close(fd_dest);

	return 0;

}