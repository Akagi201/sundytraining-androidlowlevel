#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <arpa/inet.h>
//inet op
int main()
{
	int server_fd  ; 
	struct sockaddr_in myaddr ;
	char buf[100]  ; 
	myaddr.sin_family = AF_INET  ; 
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY)  ;
	myaddr.sin_port = htons(8080)  ;
	int addr_len = sizeof(myaddr) ; 

	//1,socket
	server_fd = socket(AF_INET,SOCK_DGRAM,0)  ; 
	if(server_fd == -1)
	{
		perror("socket error")  ; 
		exit(1)  ; 
	}
	//2,bind
	if(bind(server_fd,(struct sockaddr *)&myaddr,sizeof(myaddr)) == -1)
	{
		perror("bind error")  ; 
		exit(1)  ; 
	}

	//5,op
		recvfrom(server_fd,buf,100,0,(struct sockaddr *)&myaddr,&addr_len)  ;
		printf("get from client:%s\n",buf) ; 
	//6,close 
	close(server_fd)  ; 

}
