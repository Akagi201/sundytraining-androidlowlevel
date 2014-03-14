#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork()  ;
    int count = 0 ;
    count++  ;

    if (pid == 0) {
        printf("child count:%d\n", count)  ;
    } else if (pid > 0) {
        printf("parent count:%d\n", count) ;
    }

    return  0 ;
}
