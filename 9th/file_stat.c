#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include<string.h>

int main() {
	const char *filename = "sample.txt";


	int fileDescriptor = creat(filename, 0644);
	if(fileDescriptor < 0) {
		printf("Error while creating \n");
		return 0;
	}

	const char *data = "hello this is sample file. \n";
	ssize_t byte_written = write(fileDescriptor, data, strlen(data));
	if(byte_written < 0) {
		printf("Error While Writing in File \n");
		return 0;
	}

	close(fileDescriptor);

	struct stat fileStat;

	if(stat(filename, &fileStat) < 0) {
		printf("Error while reading file stats \n");
		return 0;
	}

	// Print file information
    printf("File =  %s\n", filename);
    printf("Inode =  %ld\n", (long) fileStat.st_ino);
    printf("Number of hard links =  %ld\n", (long) fileStat.st_nlink);
    printf("UID = %d\n", fileStat.st_uid);
    printf("GID =  %d\n", fileStat.st_gid);
    printf("Size =  %ld bytes\n", (long) fileStat.st_size);
    printf("Block size =  %ld bytes\n", (long) fileStat.st_blksize);
    printf("Number of blocks =  %ld\n", (long) fileStat.st_blocks);
    printf("Time of last access = %s", ctime(&fileStat.st_atime));
    printf("Time of last modification =  %s", ctime(&fileStat.st_mtime));
    printf("Time of last change =  %s", ctime(&fileStat.st_ctime));


    return 0;
}