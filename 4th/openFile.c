#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int  main() {
	// Open File
	int fileDescriptor = open("sample.txt", O_RDWR);

	if(fileDescriptor == -1) printf("Error while opening file with open() function \n");
	else printf("Value of File Descriptor = %d\n", fileDescriptor);

	close(fileDescriptor);

	// Try opening with O_EXCL
	fileDescriptor = open("sample.txt", O_RDWR | O_CREAT | O_EXCL);

	if(fileDescriptor == -1) printf("Error while opening file with O_EXCL \n");
	else printf("Value of File Descriptor (O_EXCL) = %d \n", fileDescriptor);

	close(fileDescriptor);

	return 0;
}