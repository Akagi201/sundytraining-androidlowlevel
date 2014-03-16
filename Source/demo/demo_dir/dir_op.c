#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    DIR *dp  ;
    struct dirent *ep  ;

    //open dir
    dp = opendir("./")  ;

    if (dp != NULL) {
        while (ep = readdir(dp)) {
            puts(ep->d_name)   ;
        }
    } else {
        perror("opendir error")  ;
    }

    close(dp) ;
    return 0 ;

}
