#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid = getpid()  ; 
	printf("pid:%d\n",pid)  ; 
	pid_t ppid = getppid()  ; 
	printf("ppid:%d\n",ppid)  ; 
	return 0 ; 
}
