#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct Farm {
    int id;
    char data[100];
};


void create_farm(const char *filename) {
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct Farm farm[3] = {
        {1, "Cow"},
        {2, "Hens"},
        {3, "Pigs"}
    };

    for (int i = 0; i < 3; i++) {
        if (write(fd, &farm[i], sizeof(struct Farm)) == -1) {
            perror("Error writing to file");
            close(fd);
            exit(1);
        }
    }

    close(fd);
}

// Function to implement a write lock
void write_lock(int fd, off_t offset) {
    struct flock lock;
    lock.l_type = F_WRLCK;    // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct Farm);
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error setting write lock");
        exit(1);
    }
}


void read_lock(int fd, off_t offset) {
    struct flock lock;
    lock.l_type = F_RDLCK;    // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct Farm);
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error setting read lock");
        exit(1);
    }
}

void unlock(int fd, off_t offset) {
    struct flock lock;
    lock.l_type = F_UNLCK;    // Unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct Farm);
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error unlocking");
        exit(1);
    }
}

// Function to modify a record
void modify_farm(const char *filename, int animal_id, const char *new_animal) {
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    off_t offset = (animal_id - 1) * sizeof(struct Farm);
    
    // Lock the record for writing
    write_lock(fd, offset);

    // Read the current record
    struct Farm farm;
    lseek(fd, offset, SEEK_SET);
    if (read(fd, &farm, sizeof(struct Farm)) == -1) {
        perror("Error reading record");
        close(fd);
        exit(1);
    }

    printf("Modifying Record %d: %s -> %s\n", farm.id, farm.data, new_animal);
    
    // Modify the farm data
    strcpy(farm.data, new_animal);
    
    // Write the modified farm back
    lseek(fd, offset, SEEK_SET);
    if (write(fd, &farm, sizeof(struct Farm)) == -1) {
        perror("Error writing record");
        close(fd);
        exit(1);
    }

    // Unlock the record
    unlock(fd, offset);

    close(fd);
}

// Function to read a record
void read_farm(const char *filename, int animal_id) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    off_t offset = (animal_id - 1) * sizeof(struct Farm);
    
    read_lock(fd, offset);

    
    struct Farm farm;
    lseek(fd, offset, SEEK_SET);
    if (read(fd, &farm, sizeof(struct Farm)) == -1) {
        perror("Error reading record");
        close(fd);
        exit(1);
    }

    printf("Read Record %d: %s\n", farm.id, farm.data);

    // Unlock the record
    unlock(fd, offset);

    close(fd);
}

int main() {
    const char *filename = "farm.dat";

    // Create records
    create_farm(filename);

    read_farm(filename, 2);

    // Modify a record
    modify_farm(filename, 2, "Dog");

    // Read a record
    read_farm(filename, 2);

    return 0;
}
