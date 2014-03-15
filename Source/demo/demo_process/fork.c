#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("failure");
    } else if (pid == 0) {
        printf("child process:%d\n", getpid());
    } else {
        printf("parent process:%d\n", getpid());
    }

    return 0 ;
}
