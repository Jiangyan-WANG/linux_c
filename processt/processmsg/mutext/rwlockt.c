#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int data = 0;

// declare lock
pthread_rwlock_t rwlock;

void * fun1(void * arg)
{

    sleep(1);
    //lock
    for(int i=0;i<20;i++)
    {
        
        usleep(50000);
        pthread_rwlock_rdlock(&rwlock);
        printf("[1] read data: %d\n",data);
        printf("[1] read finished, unlock ...\n");

        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;

}

void * fun2(void * arg)
{

    sleep(1);
    //lock
    for(int i=0;i<20;i++)
    {
        usleep(50000);
        pthread_rwlock_rdlock(&rwlock);
        printf("[2] read data: %d\n",data);
        printf("[2] read finished, unlock ...\n");

        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;

}


void * fun3(void * arg)
{

    sleep(1);
    //lock
    for(int i=0;i<20;i++)
    {
        usleep(50000);
        pthread_rwlock_wrlock(&rwlock);
        data+=1;
        printf("[3] write data:%d\n",data);
        usleep(50000);
        printf("[3] write finished, unlock ...\n");

        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;

}


void * fun4(void * arg)
{

    sleep(1);
    //lock
    for(int i=0;i<20;i++)
    {
        usleep(50000);
        pthread_rwlock_wrlock(&rwlock);
        data+=1;
        printf("[4] write data:%d\n",data);
        usleep(50000);
        printf("[4] write finished, unlock ...\n");

        pthread_rwlock_unlock(&rwlock);
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
    pthread_t ctid3;
    pthread_t ctid4;
    memset(&ctid3,0,sizeof(ctid3));
    memset(&ctid4,0,sizeof(ctid4));
    
    //init lock
    pthread_rwlock_init(&rwlock, NULL);
    
    
    pthread_create(&ctid1, NULL, fun1, NULL);
    pthread_create(&ctid2, NULL, fun2, NULL);
 
    pthread_create(&ctid3, NULL, fun3, NULL);
    pthread_create(&ctid4, NULL, fun4, NULL);


    //restore

    pthread_join(ctid1,NULL);
    printf("thread 1 resotred...\n");

    pthread_join(ctid2,NULL);
    printf("thread 2 resotred...\n");

    pthread_join(ctid3,NULL);
    printf("thread 3 resotred...\n");

    pthread_join(ctid4,NULL);
    printf("thread 4 resotred...\n");


    //destroy lock
    pthread_rwlock_destroy(&rwlock);
    printf("lock destroyed...Bye\n");


    getchar();
    return 0;
}
