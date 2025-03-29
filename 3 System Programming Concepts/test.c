#include <pthread.h>
#include "tlpi-dist/lib/tlpi_hdr.h"

void *func(void *arg) {
    printf("Thread is running.\n");
    return NULL;
}

int main(){
    pthread_t thread;
    int arg = 10;
   

    int s = pthread_create(&thread, NULL, func, &arg);
    if (s != 0){
        errExitEN(s, "pthread_create");}

    // Ensure main waits for the thread to finish
    // pthread_join(thread, NULL);

}


