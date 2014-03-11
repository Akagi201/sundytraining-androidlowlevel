#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc <2)
	{
		printf("please input filename\n")  ;
		exit(1) ;
	}
	else
	{
		umask(0000) ;
		int fd ;
		fd = open(argv[1],O_RDONLY|O_CREAT,0066)  ;
		if(fd > 0)
		{
			printf("file created success\n")  ;
			char buf[1024] ;
			memset(buf,0,1024)  ;
			int rf = read(fd,buf,1024)  ; 
			if(rf != -1)
			{
				printf("buf = %s\n",buf)  ;
			}
			
			close(fd)  ;
		}else
		{
			perror("file creat failed\n")  ;
			exit(1) ;
		}
	}
	return 0  ;
}
