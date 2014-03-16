#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    struct in_addr my_addr;
    struct hostent *myhost;

    //convett a to net
    inet_aton("192.168.0.1", &my_addr);
    printf("a to net is: %#x\n", my_addr.s_addr);
    printf("address is: %s\n", inet_ntoa(my_addr));

    //get host by name
    myhost = gethostbyname("www.baidu.com");
    my_addr.s_addr = (uint32_t)(myhost->h_addr);
    printf("www.baidu.com ip is :%s\n", inet_ntoa(my_addr));

    return 0;
}
