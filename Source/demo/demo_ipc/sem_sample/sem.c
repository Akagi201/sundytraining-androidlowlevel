#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#define KEY 2234
int semid = -1 ; 

struct sembuf sem_down = {0,-1,0}  ; 
struct sembuf sem_up = {0,1,0}  ; 
union semun
{
	int val;
	struct semid_ds *buf ;
	unsigned short *array ; 
	struct seminfo *_buf  ;
} ;

void down()
{
	printf("pressing down\n")  ;
	semop(semid,&sem_down,1)  ;
}

void up()  
{
	semop(semid,&sem_up,1)  ; 
	printf("pressed up\n")  ;
}

int main()
{
	union semun arg  ;
	arg.val = 1  ; 
	//1,create sem
	semid = semget(KEY,1,IPC_CREAT|0666)  ; 
	if(semid == -1)
		perror("semget error:") ;

		//2,set semaphore = 1 
		//if(semctl(semid,1,SETVAL,arg) == -1)
		//	perror("msgctl error:")  ; 
		up() ;  // ͨ��+1 �������ź���Ϊ1
		//3,lock unlock
		down() ; //lock //-1 ���ź���Ϊ0

		printf("hello sundy\n")  ; 
		sleep(10)  ; 

		up()  ; // unlock  //��+1
	return 0 ; 
}
