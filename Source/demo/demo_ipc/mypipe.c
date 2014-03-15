#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pfd[2];
    int pid;

    char w_cont[] = " hello sundy !";
    char r_cont[255];

    //create pipe
    if (pipe(pfd) < 0) {
        //failed
        perror("create pipe failed");
        return -1;
    } else {
        if ((pid = fork()) < 0) {
            perror("create process failed");
        } else if (pid > 0) {
            //parent process
            close(pfd[0]);
            write(pfd[1], w_cont, strlen(w_cont));
            close(pfd[1]);
            wait();
        } else {
            //child process
            sleep(2);
            close(pfd[1]);
            read(pfd[0], r_cont, 255);
            printf("child process read:%s\n", r_cont);
        }

    }

    return 0;
}
