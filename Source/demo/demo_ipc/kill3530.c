#include <signal.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    //kill process 3530
    kill(3509, SIGKILL);
    printf("process 3530 was killed\n");
    return 0;
}
