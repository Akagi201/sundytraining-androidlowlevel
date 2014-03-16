#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <arpa/inet.h>

int main(void) {
    int server_fd, client_fd;
    struct sockaddr_in myaddr;
    struct sockaddr_in clientaddr;
    int client_len = sizeof(clientaddr);
    char content[] = "<html><h1>hello sundy<h1></html>";

    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(80);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (-1 == server_fd) {
        perror("socket error");
    }

    if (bind(server_fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1) {
        perror("bind error");
    }

    if (listen(server_fd, 20) == -1) {
        perror("listen error");
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&clientaddr, &client_len);

        if (-1 == client_fd) {
            perror("accept error");
        }

        printf("accept\n");

        send(client_fd, content, sizeof(content), 0);
        close(client_fd);
    }

    close(server_fd);

    return 0;
}
