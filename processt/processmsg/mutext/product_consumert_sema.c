#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
pthread_mutex_t mutex;
//sem bowl
sem_t bowl;
//sem food prepared
sem_t prepared; 

typedef struct _food
{
    int kal;
    struct _food * next;
} food;

food * head = NULL;

void * produce(void * arg)
{

    head = malloc(sizeof(food));
    head->next = NULL;

    //printf("producer start...\n");

    while(1)
    {
    
        sem_wait(&bowl);
        pthread_mutex_lock(&mutex);
        food * fo = malloc(sizeof(food));
        fo->kal = random()%100+1;

        fo->next = head->next;
        head->next=fo;

        printf("[produce ok] food energy: %d kkal.\n",fo->kal);
        pthread_mutex_unlock(&mutex);

        sem_post(&prepared);

        sleep(random()%2+1);

    }

    return NULL;
}

void * consume()
{
    //printf("condumer start...\n");

    while(1)
    {
    
        
        sem_wait(&prepared);
        
        pthread_mutex_lock(&mutex);
            food* tmp = head->next;
            head->next = head->next->next;
            printf(">>>[consume ok] got energy:%d kkal\n", tmp->kal);
            free(tmp);
        

            sem_post(&bowl);
        pthread_mutex_unlock(&mutex);
        sleep(random()%3+3);
    }


    return NULL;
}

int main()
{

    srandom(getpid());
    pthread_t producer;
    pthread_t consumer;

    pthread_mutex_init(&mutex,NULL);

    sem_init(&bowl,0,4);

    sem_init(&prepared,0,0);

    pthread_create(&producer, NULL, produce,NULL);

    pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer,NULL);

    printf("finished...\n");
    
    pthread_mutex_destroy(&mutex);
sem_destroy(&bowl);
sem_destroy(&prepared);

    return 0;
}
