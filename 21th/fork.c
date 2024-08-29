/*
============================================================================
Name : 21.c
Author : Divy Pagariya
Description : Write a program, call fork and print the parent and child process id.
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed");
        return 1;
    } else if (pid == 0) {

        printf("(when pid == 0) Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("(when pid is positive) Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
