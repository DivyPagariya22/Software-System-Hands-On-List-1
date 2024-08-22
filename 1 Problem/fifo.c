#include <sys/types.h>
#include <sys/stat.h>

int main() {
    mkfifo("myFifoSysCall", 0666);
    return 0;
}

