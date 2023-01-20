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

    //这里多线程或\产生段错误
    //head = malloc(sizeof(food));
    //head->next = NULL;

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
    //init food node
    head = malloc(sizeof(food));
    head->next = NULL;


    srandom(getpid());
    pthread_t role[6];

    for(int i=0;i<6;i++)
    {
    
        memset(role+i,0,sizeof(pthread_t));
    }

    pthread_mutex_init(&mutex,NULL);

    sem_init(&bowl,0,4);

    sem_init(&prepared,0,0);

    for(int i=0;i<6;i++)
    {
    
        if(i<4)
        {
        
    pthread_create(role+i, NULL, consume, NULL);
            //consumer
        }
        else
        {
        
    pthread_create(role+i, NULL, produce,NULL);
            //producer
        }
    }


    for(int i=0;i<6;i++)
    {
    
    pthread_join(*(role+i),NULL);
    }

    printf("finished...\n");
    
    pthread_mutex_destroy(&mutex);
sem_destroy(&bowl);
sem_destroy(&prepared);

    return 0;
}
