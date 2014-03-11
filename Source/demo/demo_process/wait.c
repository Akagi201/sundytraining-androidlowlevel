#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork()  ; 
	if(pid ==0)
	{
		printf("child process\n") ;
		sleep(5)  ;
		exit(0) ; 
	}else if(pid>0)
	{
		wait(NULL) ;
		printf("parent process\n") ;
		exit(0) ; 
	}
}
