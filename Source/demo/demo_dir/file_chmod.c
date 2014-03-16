#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
int main() {
    umask(0000)  ;
    int rt = chmod("hello", 0777) ;

    if (rt == 0) {
        printf("succes%d\n", rt)  ;
    }

    return 0 ;
}
