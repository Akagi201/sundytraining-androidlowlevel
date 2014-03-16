#include <pthread.h>
#include <stdio.h>

void *thread_function(void *arg);
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int main() {
    //create new thread
    pthread_t mythread[3];
    int i;

    for (i = 0 ; i < 3 ; i++) {
        pthread_create(&mythread[i], NULL, thread_function, (void *)i);
    }

    while (1);

    return 0;
}


void *thread_function(void *arg) {
    int i;
    pthread_mutex_lock(&mymutex);

    for (i = 0 ; i < 5 ; i++) {
        printf("thread num:%d\n", (int)arg);
    }

    pthread_mutex_unlock(&mymutex);
}
