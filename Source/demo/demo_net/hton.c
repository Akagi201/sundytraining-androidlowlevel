#include <arpa/inet.h>
#include <stdio.h>

int main() {
    int ipcount = 0x01020304;
    int ipnet = htonl(ipcount);
    printf("old is :%#x\n", ipcount);
    printf("new is :%#x\n", ipnet);
    return 0;
}
