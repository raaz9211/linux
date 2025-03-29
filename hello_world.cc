#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

void errExit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void *func(void *arg) {
    printf("Thread is running.\n");
    return NULL;
}

int main() {
    pthread_t thread;
    int arg = 10;
    
    errno = pthread_create(&thread, NULL, func, &arg);
    if (errno != 0)
        errExit("pthread_create");

    pthread_join(thread, NULL);
    return 0;
}
