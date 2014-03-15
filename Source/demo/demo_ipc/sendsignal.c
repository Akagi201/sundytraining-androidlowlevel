#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sig_handler(int sig_no) {
    if (sig_no == SIGINT) {
        printf("get SIGINT\n");
    } else if (sig_no == SIGQUIT) {
        printf("get SIGQUIT\n");
    }
}

int main() {
    printf("waiting for signal\n");
    //register signal
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    pause();
    return 0;
}
