#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main() {
    if (semctl(0, 0, IPC_RMID) != -1) {
        printf("ok\n") ;
    }

    return 0 ;

}
