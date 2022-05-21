//Name: Lukhi Krunalkumar
//ID: 201901449

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t a_done, b_done;

void* first(void* data) { 
    printf("First\n");
    sem_post(&a_done);
}

void* second(void* data) { 
    sem_wait(&a_done);
    printf("Second\n"); 
    sem_post(&b_done);
}

void* third(void* data) { 
    sem_wait(&b_done);
    printf("Third\n");
}

int main () {
    
    pthread_t t1, t2, t3;

    sem_init(&a_done, 0, 0);
    sem_init(&b_done, 0, 0);

    pthread_create(&t3, NULL, third, NULL);
    pthread_create(&t2, NULL, second, NULL);
    pthread_create(&t1, NULL, first, NULL);

    /* wait for all threads */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
}
