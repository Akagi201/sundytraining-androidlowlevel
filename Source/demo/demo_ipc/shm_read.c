#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

int main() {
    char contents[] = "hello sundy";
    void *share_memory = (void *)0;
    //1. create share memory
    int shmid = shmget(34567, 2046, IPC_CREAT | 0666);

    if (shmid != -1) {
        //2. map address
        share_memory = shmat(shmid , NULL, 0);

        if (share_memory != (void *) - 1) {
            //copy mem
            printf("get share memeory value:%s\n", (char *)share_memory);
            shmdt(share_memory);
        } else {
            perror("shmat:");
        }
    } else {
        perror("shmget:");
    }

    return 0;
}
