#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int main() {
    uint64_t start, end;

    start = __builtin_ia32_rdtsc();

    // Execute the getpid system call
    getpid();

    
    end = __builtin_ia32_rdtsc();

    uint64_t cycles = end - start;

    printf("Cycles taken to execute getpid system call: %llu\n", cycles);

    return 0;
}
