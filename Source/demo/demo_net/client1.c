#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

int main() {
    int server_fd;
    struct sockaddr_un myaddr;
    myaddr.sun_family = AF_UNIX;
    strcpy(myaddr.sun_path, "sundysocketfile");
    char buf[100];

    //1. socket
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("socket error");
        exit(1);
    }

    //2. connect
    if (connect(server_fd, (struct sockaddr *)&myaddr , sizeof(myaddr)) == -1) {
        perror("connect error");
        exit(1);
    }

    read(server_fd, buf, 100);
    printf("get message : %s\n", buf);
    close(server_fd);

    return 0;
}
