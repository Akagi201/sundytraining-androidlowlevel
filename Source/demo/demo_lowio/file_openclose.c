#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    //open file
    if (argc < 2) {
        printf("please input filename\n");
        exit(1);
    } else {
        int fd;
        umask(0000);
        fd = open(argv[1], O_RDWR | O_CREAT, 0664);

        if (fd < 0) {
            printf("error\n");
            exit(1);
        } else {
            printf("success=%d\n", fd);
            close(fd);
            printf("closed\n");
        }
    }

    return 0 ;
}
