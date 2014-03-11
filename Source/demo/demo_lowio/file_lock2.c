#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	int fd ;
	fd = open("hello",O_RDWR|O_CREAT,0666)  ;
	if(fd<0)
		exit(-1)  ;
	
	struct flock lock ;
	lock.l_type = F_WRLCK ;
	lock.l_start = 0 ; 
	lock.l_whence = SEEK_SET  ;
	lock.l_len = 0 ;
	lock.l_pid = getpid() ;

	int ret = fcntl(fd,F_SETLKW,&lock)  ;
	printf("return value of:%d\n",ret)  ;
	while(1)
		ret++  ;
}
