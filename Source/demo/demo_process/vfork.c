#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid   ;
    pid = vfork()  ;

    if (pid == -1) {
        perror("faulure")  ;
    } else if (pid == 0) {
        printf("child process:%d\n", getpid())  ;
        exit(0)  ;
    } else {
        printf("parent process:%d\n", getpid())  ;
        exit(0) ;
    }

    return 0 ;
}
