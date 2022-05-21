//Name: Lukhi Krunalkumar
//ID: 201901449

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t a_done,b_done;

void* even(void* data) 
{
    for(int i=2;i<=100;i+=2)
    {
	    sem_wait(&b_done);
	    printf("%d ",i);
	    sem_post(&a_done);
    }
}

void* odd(void* data) 
{
    for(int i=1;i<100;i+=2)
    {
	    sem_wait(&a_done);
	    printf("%d ",i);
	    sem_post(&b_done);
    }
}

int main () {

    pthread_t t1, t2;

    sem_init(&a_done,0,0);
    sem_init(&b_done,0,0);

    sem_post(&a_done);

    pthread_create(&t1, NULL, odd, NULL);
    pthread_create(&t2, NULL, even, NULL);
    
    /* wait for all threads */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("\n");
    
    return 0;
}
