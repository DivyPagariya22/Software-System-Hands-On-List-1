#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed");
        return 1;
    } else if (pid == 0) {

        printf("(when pid == 0) Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        sleep(5); // Makes child process go in zombie state

        //Init Adopts it
        printf("(when pid == 0) Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // exit(0);

    } else {
        printf("(when pid is positive) Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        exit(0);
    }

    return 0;
}
