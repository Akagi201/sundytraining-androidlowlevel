#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    DIR *dp  ;
    struct dirent *ep  ;

    dp = opendir("./")  ;

    if (dp != NULL) {
        while (ep = readdir(dp)) {
            puts(ep->d_name)  ;
        }

        closedir(dp)  ;
    } else {
        perror("Can't open the dir") ;
    }

    return 0 ;
}
