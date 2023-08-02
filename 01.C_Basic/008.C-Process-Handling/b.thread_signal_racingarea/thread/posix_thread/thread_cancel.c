#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* target_function(void* arg) {
    char* buf = "Hello from thread\n";
    printf("Thread started.\n");
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    write(STDOUT_FILENO, buf, strlen(buf));

    /* Thread never reaches here */
    sleep(3);
    printf("Thread finishes normally!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, target_function, NULL);
    pthread_cancel(thread);
    pthread_join(thread, NULL);
    printf("Main thread finished.\n");
    fflush(stdout);
    return EXIT_SUCCESS;
}