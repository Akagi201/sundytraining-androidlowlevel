#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
int main() {
    int fd;
    fd = open("hello", O_RDWR | O_CREAT, 0664);

    if (fd > 0) {
        flock("hello", LOCK_EX);
    }

    int i;

    while (1) {
        ++i;
    }
}
