#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define FIFO_PATH "myfifofile"

//read fifo
int main() {
    int fd;
    char cont_r[255];

    //create fifo file
    if (mkfifo(FIFO_PATH, 0666) < 0 && errno != EEXIST) {
        perror("create fifo failed");
        return -1;
    } else {
        printf("create fifo success\n");
        //open fifo file
        fd = open(FIFO_PATH, O_CREAT | O_RDONLY, 0666);

        if (fd > 0) {
            //read content
            while (1) {
                read(fd, cont_r, 255);
                printf("read:%s\n", cont_r);
            }

            close(fd);
        } else {
            perror("open failed");
        }

        return 0;

    }

}
