#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define FILE_MAX 66504   
void init_daemon(void)
{
	pid_t pid  ; 
	int i ;
	if(pid = fork())
	{
		printf("exit 1\n")  ;
		exit(0) ; 
	}
	else if(pid < 0)
		exit(1)   ;

	setsid()  ; 

	/*if(pid=fork())
	{
		printf("exit 2\n")  ;
		exit(0)  ; 
	}
	else if(pid < 0)
		exit(1)  ; 
	*/
	for(i=0;i<FILE_MAX;i++)
	{	
		close(i) ; 
	}
	
	chdir("/")  ;
	umask(0)  ;
	return ;
}

int main()
{
	int fd  ;
	char *cont = "hello sundy\n" ;
	init_daemon()  ; 
	while(1)
	{
		fd = open("/tmp/sundy.log",O_RDWR|O_CREAT|O_APPEND,0666)  ; 
		if(fd>0)
		{
			write(fd,cont,strlen(cont))  ; 
			close(fd)  ;
		}
		sleep(5)  ; 
	}
}
