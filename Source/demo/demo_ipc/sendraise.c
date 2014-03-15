#include <signal.h>
#include <stdio.h>

int main() {
    int pid;

    if ((pid = fork()) < 0) {
        printf("error\n");
    } else if (pid == 0) {
        raise(SIGKILL);
        printf("child process \n");
    } else {
        raise(SIGSTOP);
        printf("parent process\n");
    }

    return 0;

}
