#include <unistd.h>

int main() {
    execl("/bin/ps", "ps", "-ef", NULL)  ;
    return 0 ;
}
