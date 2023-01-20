#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// declare lock
pthread_mutex_t lock;

void * fun1(void * arg)
{

    sleep(1);
    //lock
    for(int i=0;i<20;i++)
    {
    pthread_mutex_lock(&lock);

    for(char i = 'A';i<='Z';i++)
    {
        usleep(10000);


        printf("%c",i);
        fflush(stdout);
    }

    printf("\n");
    //unlock

    pthread_mutex_unlock(&lock);
    }
    return NULL;

}

void * fun2(void * arg)
{

    
    sleep(1);
    
    for(int i=0;i<20;i++)
    {
        pthread_mutex_lock(&lock);
    for(char i = 'a';i<='z';i++)
    {
    
        usleep(10000);
        printf("%c",i);
        fflush(stdout);
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
    }
    return NULL;

}


int main()
{

    //init
    pthread_t ctid1;
    pthread_t ctid2;
    memset(&ctid1,0,sizeof(ctid1));
    memset(&ctid2,0,sizeof(ctid2));
    
    //init lock
    pthread_mutex_init(&lock, NULL);
    
    
    pthread_create(&ctid1, NULL, fun1, NULL);
    pthread_create(&ctid2, NULL, fun2, NULL);

    //restore

    pthread_join(ctid1,NULL);
    

    printf("thread 1 resotred...\n");

    pthread_join(ctid2,NULL);
    printf("thread 1 resotred...\n");

    //destroy lock
    pthread_mutex_destroy(&lock);
    printf("lock destroyed...Bye\n");


    getchar();
    return 0;
}
