#include <unistd.h>

int main()
{
	execlp("ps","ps","-ef",NULL)  ; 
	return 0 ; 
}
