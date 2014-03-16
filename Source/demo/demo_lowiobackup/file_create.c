#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("please input filename\n")  ;
        exit(1) ;
    } else {
        umask(0000) ;
        int fd ;
        fd = open(argv[1], O_RDONLY | O_CREAT, 0066)  ;

        if (fd > 0) {
            printf("file created success\n")  ;
            close(fd)  ;
        } else {
            perror("file creat failed\n")  ;
            exit(1) ;
        }
    }

    return 0  ;
}
