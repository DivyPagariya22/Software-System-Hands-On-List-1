/*
============================================================================
Name : 27.c
Author : Divy Pagariya
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date : 30th Aug 2024
============================================================================
*/


#include <unistd.h>
#include <stdio.h>

int main() {
    int choice;
    printf("Choose the exec function to run:\n");
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            execl("/bin/ls", "ls", "-Rl", NULL);
            printf("execl failed \n");
            break;
        case 2:
            execlp("ls", "ls", "-Rl", NULL);
			printf("execl failed \n");
            break;
        case 3: {
            char *envp[] = {NULL};
            execle("/bin/ls", "ls", "-Rl", NULL, envp);
            printf("execl failed \n");
            break;
        }
        case 4: {
            char *args[] = {"ls", "-Rl", NULL};
            execv("/bin/ls", args);
            printf("execl failed \n");
            break;
        }
        case 5: {
            char *args[] = {"ls", "-Rl", NULL};
            execvp("ls", args);
            printf("execl failed \n");
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
