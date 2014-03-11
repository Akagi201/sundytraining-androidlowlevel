#include <unistd.h>
#include <stdio.h>
int main()
{
	int count = 0 ;
	pid_t pid = fork()  ;
	if(pid == -1)
		perror("faled")  ;
	else if(pid == 0)
	{
		count++  ;
		printf("child process pid:%d\n",count)  ; 
	}
	else if(pid > 0)
	{
		count++  ;
		printf("parent process pid:%d\n",count)  ;
	}
	return 0 ; 
}
