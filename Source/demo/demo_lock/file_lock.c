#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    //open file
    int fd = open("hello.txt", O_RDWR | O_CREAT, 0666)  ;

    if (fd > 0) {
        //lock file
        struct flock lock  ;
        lock.l_type = F_WRLCK ;
        lock.l_whence = SEEK_SET  ;
        lock.l_start = 0 ;
        lock.l_len = 0 ;
        lock.l_pid = getpid()  ;
        int rd = fcntl(fd, F_SETLK, &lock)  ;
        printf("return value of lock:%d\n", rd)  ;

        while (1) {
            rd++  ;
        }
    }
}
