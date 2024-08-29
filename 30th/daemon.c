/*
============================================================================
Name : 30.c
Author : Divy Pagariya
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <errno.h>

void create_daemon() {
    pid_t pid;


    pid = fork();

    if (pid < 0) {

        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }


    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);


    for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
        close(x);
    }
}

// Function to run the script at the specified time
void run_script_at_time(const char *script_path, int hour, int minute) {
    time_t now;
    struct tm *current_time;

    while (1) {

        now = time(NULL);
        current_time = localtime(&now);

        if (current_time->tm_hour == hour && current_time->tm_min == minute) {
            if (system(script_path) == -1) {
                perror("Failed to execute script");
            }
            break;
        }


        sleep(60);
    }
}

int main() {
    const char *script_path = "./simple_script.sh";
    int hour = 16;
    int minute = 55;


    create_daemon();

    // if (system(script_path) == -1) {
    //     perror("Failed to execute script");
    // }


    run_script_at_time(script_path, hour, minute);

    return 0;
}
