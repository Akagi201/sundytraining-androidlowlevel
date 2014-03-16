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

int main(int argc , char *argv[]) {
    if (argc < 2) {
        perror("argment count error");
        exit(1);
    }

    int server_fd;
    struct hostent *myhost;
    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myhost = gethostbyname(argv[1]);

    if (!myhost) {
        perror("gethost error");
        exit(1);
    }

    myaddr.sin_addr = *((struct in_addr *)myhost->h_addr);
    myaddr.sin_port = htons(8080);
    char buf[100];

    //1. socket
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_fd == -1) {
        perror("socket error");
        exit(1);
    }

    // 2. sendto
    sendto(server_fd, "nice to meet you .", 11, 0, (struct sockaddr *)&myaddr, sizeof(myaddr));
    printf("send to success!\n");

    // 3. close
    close(server_fd);

    return 0;
}
