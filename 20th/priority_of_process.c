#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
	pid_t pid = getpid();

	int priority = getpriority(PRIO_PROCESS, pid);
	if(priority == -1) {
		printf("error while fetching priority \n");
		return 0;
	}

	printf("Current priority (nice value) of the process: %d\n", priority);

	int new_nice_val = 5;
	int new_priority = nice(new_nice_val);

    if (new_priority == -1) {
        printf("Error setting priority with nice");
        return 0;
    }

    // printf("New priority (nice value) of the process: %d\n", new_priority);


    priority = getpriority(PRIO_PROCESS, pid);
	if(priority == -1) {
		printf("error while fetching priority \n");
		return 0;
	}

	printf("New priority (nice value) of the process: %d\n", priority);

}