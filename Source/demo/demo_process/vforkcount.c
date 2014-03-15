#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int count = 0;
    pid_t pid = vfork();
    count++;

    if (pid == 0) {
        printf("child count:%d\n", count);
        exit(0);
    } else if (pid > 0) {
        printf("parent count:%d\n", count);
        exit(0);
    }

    return  0 ;
}
