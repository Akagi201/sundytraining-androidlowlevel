#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("please input filename\n")  ;
        exit(1) ;
    } else {
        umask(0000) ;
        int fd ;
        fd = open(argv[1], O_RDWR | O_CREAT, 0666)  ;

        if (fd > 0) {
            char buf[] = "hello sundy\n" ;
            int rf = write(fd, buf, strlen(buf))  ;

            if (rf != -1) {
                printf("file created success%d\n", rf)  ;
                int pos = lseek(fd, 3, SEEK_SET)  ;
                char buf2[1024]  ;
                memset(buf2, 0, 1024)  ;
                read(fd, buf2, 1024)  ;
                printf("buf2=%s\n", buf2)  ;
            } else {
                perror("err:")  ;
            }

            close(fd)  ;
        } else {
            perror("file creat failed\n")  ;
            exit(1) ;
        }
    }

    return 0  ;
}
