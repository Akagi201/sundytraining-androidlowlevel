#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("process id: %d\n", getpid());
    return  0;
}
