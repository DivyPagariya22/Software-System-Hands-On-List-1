/*
============================================================================
Name : 25.c
Author : Divy Pagariya
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int status;
    pid_t pid1, pid2, pid3;
    

    pid1 = fork();
    
    if (pid1 < 0) {
        printf("Fork failed for child 1 \n");
        exit(1);
    } else if (pid1 == 0) {

        printf("Child 1: PID = %d\n", getpid());
        sleep(2);  
        exit(1);   
    }

    pid2 = fork();
    
    if (pid2 < 0) {
        printf("Fork failed for child 2 \n");
        exit(1);
    } else if (pid2 == 0) {
        
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);  
        exit(2);  
    }

    
    pid3 = fork();
    
    if (pid3 < 0) {
        printf("Fork failed for child 3\n");
        exit(1);
    } else if (pid3 == 0) {
    
        printf("Child 3: PID = %d\n", getpid());
        sleep(6);  
        exit(3); 
    }

    
    printf("Parent process: Waiting for Child 2 (PID = %d) to finish...\n", pid2);
    waitpid(pid2, &status, 0);

    
    if (WIFEXITED(status)) {
        printf("Parent process: Child 2 (PID = %d) finished with exit status %d\n", pid2, WEXITSTATUS(status));
    } else {
        printf("Parent process: Child 2 (PID = %d) did not terminate normally\n", pid2);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid3, NULL, 0);

    printf("Parent process: All children have finished.\n");
    return 0;
}
