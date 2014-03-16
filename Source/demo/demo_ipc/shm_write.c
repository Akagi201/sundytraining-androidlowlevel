#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

int main() {
    char contents[] = "hello sundy";
    void *share_memory = (void *)0;
    //1. create share memory // ftok 根据文件生成一个唯一的key
    int shmid = shmget(34567, 2046, IPC_CREAT | 0666);

    if (shmid != -1) {
        //2. map address
        share_memory = shmat(shmid , NULL, 0);

        if (share_memory != (void *) - 1) {
            //copy mem
            memcpy(share_memory, contents, 12);
            printf("save successed\n");
            shmdt(share_memory);
        } else {
            perror("shmat:");
        }
    } else {
        perror("shmget:");
    }

    return 0;
}
