#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int rt = unlink("hello") ;
	if(rt==0)
		printf("succes%d\n",rt)  ; 

	return 0 ;
}
