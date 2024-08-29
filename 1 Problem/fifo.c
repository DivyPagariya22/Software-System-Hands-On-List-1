/*
============================================================================
Name : 1c.c
Author : Divy Pagariya
Description : Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 22th Aug, 2024.
============================================================================
*/



#include <sys/types.h>
#include <sys/stat.h>

int main() {
    mkfifo("myFifoSysCall", 0666);
    return 0;
}

