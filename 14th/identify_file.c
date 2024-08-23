#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void print_file_type(const char *file_path) {
    struct stat file_info;

    if (stat(file_path, &file_info) != 0) {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

   
    if (S_ISREG(file_info.st_mode)) {
        printf("%s is a regular file.\n", file_path);
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("%s is a directory.\n", file_path);
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("%s is a symbolic link.\n", file_path);
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("%s is a character device.\n", file_path);
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("%s is a block device.\n", file_path);
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", file_path);
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("%s is a socket.\n", file_path);
    } else {
        printf("%s is of an unknown file type.\n", file_path);
    }
}

int main() {
    char file_path[1024];


    printf("Enter the file path: ");
    if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
        printf("Error while reading path\n");
        return 0;
    }

    
    file_path[strcspn(file_path, "\n")] = '\0';

    print_file_type(file_path);

    return 0;
}
