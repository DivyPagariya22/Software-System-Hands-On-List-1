#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main() {

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Read
    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        // Write
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    return 0;
}
