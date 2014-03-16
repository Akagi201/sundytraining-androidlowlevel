#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msgbuf {
    long mtype;
    char mtext[255];
};

int main() {
    struct msgbuf mybuf;
    mybuf.mtype = 1;
    strcpy(mybuf.mtext, "hello sundy");


    //1,create message queue
    int msgqid = msgget(2345, IPC_CREAT | 0666);

    if (msgqid != -1) {
        //2,send message
        if (msgsnd(msgqid, &mybuf , sizeof(mybuf.mtext), 0) != -1) {
            printf("send message sucessed\n");
        } else {
            perror("msgsnd error:");
        }
    } else {
        perror("msgget error:");
    }

    return 0;
}
