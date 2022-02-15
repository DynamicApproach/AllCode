#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int sum =0;

void* count_sum(void *arg) {
    int i = 0;
    for (i = 0; i < 499999; i++) {
        sum += rand()%10;
    }
    return NULL;
}
void* count_sum2(void *arg) {
    for (int i = 500000; i < 999999; i++) {
        sum += rand()%10;
    }     
        return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, count_sum, NULL);
    pthread_create(&thread2, NULL, count_sum2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("sum = %d\n", sum);


      return 0;
}