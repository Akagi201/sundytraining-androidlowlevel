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
			//read file 
			char buf[1024]  ; 
			memset(buf,0,1024)  ; 
			int returnum = read(fd, buf,1024)  ;
			if(returnum != -1)
			{
				//sucess
				printf("buf=%s\n",buf)  ; 
				int file_len = lseek(fd,0,SEEK_END)  ;
				printf("file length=%d\n",file_len)  ; 
			}else
			{
				printf("error\n")  ; 
			}
			close(fd)  ; 
			printf("closed\n")  ; 
		}
	}
	return 0 ; 
}
