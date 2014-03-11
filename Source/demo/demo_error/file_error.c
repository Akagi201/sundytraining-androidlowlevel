#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("hello",O_RDONLY,0666)  ; 
	if(fd<0)
	{
		perror("open error")  ; 
	}
	return 0 ; 
}
