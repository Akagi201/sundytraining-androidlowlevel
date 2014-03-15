#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main() {
    int a;
    alarm(3);
    pause();
    printf("exit\n");
    return 0;
}
