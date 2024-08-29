/*
============================================================================
Name : 26.c
Author : Divy Pagariya
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 27th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *program = "./a.out";  // The executable to run
    printf("Executing %s\n", program);

    // Execute the program with arguments using execv
    if (execl(program, program, NULL) == -1) {
        printf("execv failed \n");
        exit(1);
    }

    // This line will not be reached if execv is successful
    printf("This line will not be executed.\n");
    return 0;
}
