#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msgbuf
{
	long mtype ;
	char mtext[255]  ; 
};

int main()
{
	struct msgbuf mybuf  ; 
	//mybuf.mtype = 1  ; 
	//strcpy(mybuf.mtext,"hello sundy")  ; 


	//1,create message queue 
	int msgqid = msgget(2345,IPC_CREAT|0666)  ; 
	if(msgqid != -1)
	{
		//2,receive message
		if(msgrcv(msgqid,&mybuf , sizeof(mybuf.mtext),0,IPC_NOWAIT) != -1)
		{
			printf("receive message :%s\n",mybuf.mtext)  ; 
			//3,delete queue 
			if(msgctl(msgqid , IPC_RMID,0) != -1) 
				printf("delete queue sucessed\n")  ; 
		}else
		perror("msgsnd error:")  ; 
	}else
	perror("msgget error:") ; 

	return 0 ; 
}
