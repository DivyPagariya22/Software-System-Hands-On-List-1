/*
============================================================================
Name : 28.c
Author : Divy Pagariya
Description : Write a program to get maximum and minimum real time priority.
Date: 22th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {


    int min_priority_rr;
    int min_priority_fifo;
    int max_priority_fifo;
    int max_priority_rr;
    


    min_priority_fifo = sched_get_priority_min(SCHED_FIFO);
    if (min_priority_fifo == -1) {
        perror("SCHED_FIFO failed");
        exit(EXIT_FAILURE);
    }

    min_priority_rr = sched_get_priority_min(SCHED_RR);
    if (min_priority_rr == -1) {
        perror("SCHED_RR failed");
        exit(EXIT_FAILURE);
    }

    max_priority_fifo = sched_get_priority_max(SCHED_FIFO);
    if (max_priority_fifo == -1) {
        perror("SCHED_FIFO failed");
        exit(EXIT_FAILURE);
    }
    
    max_priority_rr = sched_get_priority_max(SCHED_RR);
    if (max_priority_rr == -1) {
        perror("SCHED_RR failed");
        exit(EXIT_FAILURE);
    }


    // Print the results
    printf("Real-time scheduling priorities:\n");
    
    printf("SCHED_RR:\n");
    printf("  Maximum priority: %d\n", max_priority_rr);
    printf("  Minimum priority: %d\n", min_priority_rr);

    printf("SCHED_FIFO:\n");
    printf("  Maximum priority: %d\n", max_priority_fifo);
    printf("  Minimum priority: %d\n", min_priority_fifo);


    return 0;
}
