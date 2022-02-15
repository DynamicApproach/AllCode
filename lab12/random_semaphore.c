#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>



int sum =0;
// semaphore to wrap sum
sem_t sem_resource;

void* count_sum(void *arg) {
    int i = 0;
    for (i = 0; i < 499999; i++) {
        sem_wait(&sem_resource);
        sum += rand()%10;
        sem_post(&sem_resource);
    }



    return NULL;
}
void* count_sum2(void *arg) {
    for (int i = 500000; i < 999999; i++) {
        sem_wait(&sem_resource);
        sum += rand()%10;
        sem_post(&sem_resource);
    }     
        return NULL;

}

int main()
{
    sem_init(&sem_resource, 0, 1);

    srand(time(NULL));
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, count_sum, NULL);
    pthread_create(&thread2, NULL, count_sum2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("sum = %d\n", sum);


    sem_destroy(&sem_resource);
      return 0;
}