#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//open file 
	if(argc<2)
	{
		printf("please input filename\n")  ; 
		exit(1)  ; 
	}else
	{
		int fd  ; 
		umask(0000) ; 
		fd = open(argv[1],O_RDWR|O_CREAT,0664)  ; 
		if(fd < 0)
		{
			printf(" error\n")  ; 
			exit(1) ; 
		}else
		{
			printf("success=%d\n",fd)  ; 
			//write file 
			char buf[] = "hello sundy!\n"  ; 
			int returnum = write(fd, buf,strlen(buf))  ;
			
			//seek file
			lseek(fd,5,SEEK_SET)  ; 
			char buf2[1024]   ; 
			memset(buf2,0,1024)  ; 
			//read
			read(fd,buf2,1024)  ; 
			printf("buf2=%s\n",buf2)  ; 


			if(returnum != -1)
			{
				//sucess
			}else
			{
				printf("error\n")  ; 
			}
			close(fd)  ; 
		}
	}
	return 0 ; 
}
