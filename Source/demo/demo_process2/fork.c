#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid = fork()  ;
	if(pid == -1)
		perror("faled")  ;
	else if(pid == 0)
		printf("child process pid:%d\n",getpid())  ; 
	else if(pid > 0)
		printf("parent process pid:%d\n",getpid())  ;
	return 0 ; 
}
