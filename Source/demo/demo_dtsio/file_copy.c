#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include <stdlib.h>

int main() {
    FILE *fpin , *fpout ;
    char c ;
    fpin = fopen("file.in", "rt")  ;
    fpout = fopen("file.out", "w+")  ;

    while ((c = fgetc(fpin)) != EOF) {
        fputc(c, fpout) ;
    }

    fclose(fpin)  ;
    fclose(fpout)  ;

    printf("get pid:%d\n", getpid()) ;
    return 0 ;

}
