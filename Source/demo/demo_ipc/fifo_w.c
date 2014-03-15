#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define FIFO_PATH "myfifofile"

//write fifo
int main() {
    int fd;
    char cont_w[] = "hello sundy !";

    //create fifo file
    if (mkfifo(FIFO_PATH, 0666) < 0 && errno != EEXIST) {
        perror("create fifo failed");
        return -1;
    } else {
        printf("create fifo success\n");
        //open fifo file
        fd = open(FIFO_PATH, O_CREAT | O_WRONLY, 0666);

        if (fd > 0) {
            //read content
            while (1) {
                write(fd, cont_w, strlen(cont_w));
                printf("write sucess\n");
                sleep(2);

            }

            close(fd);
        } else {
            perror("open failed");
        }

        return 0;
    }

}
