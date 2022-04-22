/* shopping.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *print_produce( void * );
void *print_dairy( void * );

sem_t mutex;
// Salad < Butter and Milk < Apples
void *print_dairy(void *items)
{
int i = 0;
char** array = (void*)items;
{
    // sem up
printf("got %s\n", (array[i++]) ); // milk
sem_post(&mutex);
printf("got %s\n", (array[i++]) ); // butter
sem_post(&mutex);
}
return( NULL );
}

void *print_produce(void *items)
{
int i = 0;
char** array = (void*)items;
{
    sem_wait(&mutex);
    printf("got %s\n", (array[i++]) ); // salad
    sem_wait(&mutex);
    printf("got %s\n", (array[i++]) ); // apple
    sem_post(&mutex);
}
return( NULL );
}

int main()
{
// init sem
sem_init(&mutex, 0, 1);

char *produce[] = { "Salad", "Apples", NULL };
char *dairy[] = { "Milk", "Butter", NULL };
pthread_t th1, th2;
pthread_create( &th1, NULL, print_produce, (void*)produce);
pthread_create( &th2, NULL, print_dairy, (void*)dairy);
pthread_join(th1, NULL);
pthread_join(th2, NULL);
sem_destroy(&mutex);
}