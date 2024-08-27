#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {

    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        default:
            printf("Unknown\n");
    }
}

int main() {
    int policy;
    struct sched_param param;

    
    policy = sched_getscheduler(0); 
    if (policy == -1) {
        printf("sched_getscheduler failed \n");
        return 0;
    }

    print_policy(policy);

    printf("Modifying scheduling policy to SCHED_FIFO...\n");
    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        printf("sched_setscheduler failed for SCHED_FIFO %s\n",  strerror(errno));
        return 0;
    }

    // Verify the change
    policy = sched_getscheduler(0);
    if (policy == -1) {
        printf("sched_getscheduler failed \n");
        return 0;
    }

    print_policy(policy);


    printf("Modifying scheduling policy to SCHED_RR...\n");
    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        printf("sched_setscheduler failed for SCHED_RR \n");
        return 0;
    }

    // Verify the change
    policy = sched_getscheduler(0);
    if (policy == -1) {
        printf("sched_getscheduler failed \n");
        return 0;
    }

    print_policy(policy);

    return 0;
}
