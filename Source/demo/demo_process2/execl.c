#include <unistd.h>
int main()
{
	char *argvs[] = {"ps","-ef",NULL}  ;
	execv("/bin/ps",argvs)  ;
	return 0 ; 
}
