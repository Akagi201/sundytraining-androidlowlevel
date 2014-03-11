#include <arpa/inet.h>
#include <stdio.h>

int main()
{
	int ipcount = 0x01020304  ; 
	int ipnet = htonl(ipcount)  ; 
	printf("old is :%d\n",ipcount)  ; 
	printf("new is :%d\n",ipnet)  ; 
	return 0 ; 
}
