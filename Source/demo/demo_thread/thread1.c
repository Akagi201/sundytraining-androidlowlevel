#include <pthread.h>
#include <stdio.h>

void *thread_function(void *arg);

int main() {
    //create new thread
    char message[] = "hello sundy";
    void *retval;
    pthread_t mythread;

    if (pthread_create(&mythread , NULL, thread_function , (void *)message) == 0) {
        printf("create thread sucessed\n");
    }

    pthread_join(mythread, &retval);
    printf("get result:%s\n", (char *)retval);

    return 0;
}


void *thread_function(void *arg) {
    printf("thread get message:%s\n", (char *)arg);
    pthread_exit("good bye");
}
