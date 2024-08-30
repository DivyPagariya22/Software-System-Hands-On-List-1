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
    char *program = "./a.out";  
    printf("Executing %s\n", program);

    if (execl(program, program, NULL) == -1) {
        printf("execv failed \n");
        exit(1);
    }

    
    printf("This line will not be executed.\n");
    return 0;
}
