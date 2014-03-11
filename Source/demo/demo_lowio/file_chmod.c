#include <sys/stat.h>

int main()
{
	umask(0000) ;
	chmod("hello2",0777)  ; 
	return 0  ; 
}
