#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/wait.h>

void error_and_die(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int r, r2;

    const char *memname = "data";
    const size_t region_size = 10000;

    int fd = shm_open(memname, O_CREAT | O_TRUNC | O_RDWR, 0666);
    int data = open("datacopied", O_RDWR);
    if (fd == -1)
        error_and_die("shm_open");

    r = ftruncate(fd, region_size);
    if (r != 0)
        error_and_die("ftruncate");
    r2 = ftruncate(data, region_size);
    if (r != 0)
        error_and_die("ftruncate");

    char *data_ptr = mmap(NULL, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, data, 0);
    if (data_ptr == MAP_FAILED)
        error_and_die("mmap");

    void *ptr = mmap(0, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
        error_and_die("mmap");

    // mem copy
    memcpy(ptr, data_ptr, region_size);
    close(fd);
    close(data);

    return 0;
}