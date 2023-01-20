#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

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
    
        pthread_mutex_lock(&mutex);
        food * fo = malloc(sizeof(food));
        fo->kal = random()%100+1;

        fo->next = head->next;
        head->next=fo;

        printf("[produce ok] food energy: %d kkal.\n",fo->kal);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

        sleep(random()%3+2);

    }

    return NULL;
}

void * consume()
{
    //printf("condumer start...\n");

    while(1)
    {
    
        pthread_mutex_lock(&mutex);
        if(head->next!=NULL)
        {
        
            food* tmp = head->next;
            head->next = head->next->next;
            printf(">>>[consume ok] got energy:%d kkal\n", tmp->kal);
            free(tmp);
        }
        else
        {
            //printf("food is already empty...wait for a while\n");
        
            //add cond wait at the place where should block and wait
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_unlock(&mutex);
        sleep(random()%2+2);
    }


    return NULL;
}

int main()
{

    srandom(getpid());
    pthread_t producer;
    pthread_t consumer;

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_create(&producer, NULL, produce,NULL);

    pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer,NULL);

    printf("finished...\n");
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
