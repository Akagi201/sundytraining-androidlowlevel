#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int i ; 
	int fd ;
	char *content = "sundy print log\n"  ; 
	//1,create a child process , exit parent
	pid_t pid = fork()  ; 
	if(pid<0)
		exit(1) ; 
	else if(pid>0)
		exit(0)  ; 
	//set new session
    setsid()  ; 
	//2,close all fd
	for(i=0;i<101122;i++)
	{
		close(i) ; 
	}
	//3,change dir 
	chdir("/")  ; 
	//4,umask
	umask(0) ; 
	//5,event
	while(1)
	{
		fd = open("/tmp/mylog.log",O_CREAT|O_RDWR|O_APPEND,06666)  ; 
		if(fd>0)
		{
			write(fd,content,strlen(content))  ; 
			close(fd)  ; 
		}
		sleep(3)  ; 
	}
}
