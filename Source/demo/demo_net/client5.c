#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc , char *argv[])
{
	if(argc <2)
	{
		perror("argment count error")  ; 
		exit(1) ; 
	}

	int server_fd  ; 
	struct hostent *myhost ;
	struct sockaddr_in myaddr ;
	myaddr.sin_family = AF_INET  ;
	myhost = gethostbyname(argv[1])  ; 
	if(!myhost)
	{
		perror("gethost error") ; 
		exit(1) ;
	}
	myaddr.sin_addr = *((struct in_addr *)myhost->h_addr)  ;
	myaddr.sin_port = htons(8080)  ; 
	char buf[100]  ; 

	//1,socket
	server_fd = socket(AF_INET,SOCK_STREAM,0)  ; 
	if(server_fd == -1)
	{
		perror("socket error")  ; 
		exit(1)  ; 
	}
	//2,connect 
	if(connect(server_fd,(struct sockaddr *)&myaddr , sizeof(myaddr)) == -1)
	{
		perror("connect error") ;
		exit(1) ; 
	}

	recv(server_fd,buf,100,0)  ; 
	printf("get message : %s\n",buf)  ; 
	close(server_fd)  ; 
}
