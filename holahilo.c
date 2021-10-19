#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

void * printHola(void* arg) {
    char *c = (char *)arg;
    printf("Hola desde un hilo %s \n", c);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    char *s = "soy un argumento";
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, printHola,(void *) s);
    }
    pthread_exit(NULL);
    return 0;
}