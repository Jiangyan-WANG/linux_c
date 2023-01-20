#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int flag = 0;
void * fun1(void * arg)
{

    sleep(3);
    for(int i=0;i<10;i++)
    {
    pthread_mutex_lock(&mutex);
    if(flag == 0)
    {
    
        printf("condition not ok...wait...\n");
    // hide one unlock of mutex before wait and a lock of mutex after inside
        pthread_cond_wait(&cond, &mutex);
    }
    printf("condition ok...work...\n");

        flag = 0;
        pthread_mutex_unlock(&mutex);
    }


   return NULL;

}
void * fun2(void * arg)
{

    //switch condition timer

    for(int i=0;i<10;i++)
    {
        sleep(2);
        
    pthread_mutex_lock(&mutex);

    flag=1;

    printf("condition changed...awake...\n");

    pthread_mutex_unlock(&mutex);

    pthread_cond_signal(&cond);
    }

   return NULL;

}



int main()
{

    pthread_t ctid1;
    pthread_t ctid2;
    memset(&ctid1,0,sizeof(ctid1));
    memset(&ctid2,0,sizeof(ctid2));

    //init lock
    //

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond,NULL);


    pthread_create(&ctid1, NULL, fun1, NULL);
    pthread_create(&ctid2, NULL, fun2, NULL);

    //restore

    pthread_join(ctid1,NULL);
    
    printf("\n");

    printf("thread 1 resotred...\n");

    pthread_join(ctid2,NULL);
    printf("thread 2 resotred...\n");

    //destroy lock
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
