/*
============================================================================
Name : 5.c
Author : Divy Pagariya
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 22th Aug, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main() {
	const char *filenames[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
	int fd[5];


	for(int i = 0; i < 5; i++) {
		char fileName[30];

		strcpy(fileName, filenames[i]);

		fd[i] = open(fileName, O_CREAT | O_RDWR, 0644);

		if(fd[i] == -1) printf("Error while creating file%d \n", i);
		else printf("Created %s with file Descriptor value = %d\n",fileName, fd[i]);

	}

	while(1) {
		sleep(1);
	}

	return 0;


}