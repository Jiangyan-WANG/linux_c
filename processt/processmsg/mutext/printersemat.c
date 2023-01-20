#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
// declare lock
sem_t sem;

void * fun1(void * arg)
{

    sleep(1);
    //lock
    for(int i=0;i<20;i++)
    {

    sem_wait(&sem);
    for(char i = 'A';i<='Z';i++)
    {
        usleep(10000);


        printf("%c",i);
        fflush(stdout);
    }

    printf("\n");
    //unlock

    sem_post(&sem);

    sleep(random()%2+1);
    }
    return NULL;

}

void * fun2(void * arg)
{

    
    sleep(1);
    
    for(int i=0;i<20;i++)
    {
        sem_wait(&sem);
    for(char i = 'a';i<='z';i++)
    {
    
        usleep(10000);
        printf("%c",i);
        fflush(stdout);
    }
    printf("\n");
    sem_post(&sem);
    sleep(random()%2+1);
    }
    return NULL;

}


int main()
{

    srandom(getpid());
    //init
    pthread_t ctid1;
    pthread_t ctid2;
    memset(&ctid1,0,sizeof(ctid1));
    memset(&ctid2,0,sizeof(ctid2));
    
    //init lock
    sem_init(&sem,0,1);
    
    pthread_create(&ctid1, NULL, fun1, NULL);
    pthread_create(&ctid2, NULL, fun2, NULL);

    //restore

    pthread_join(ctid1,NULL);
    

    printf("thread 1 resotred...\n");

    pthread_join(ctid2,NULL);
    printf("thread 1 resotred...\n");

    //destroy lock
    sem_destroy(&sem);
    printf("lock destroyed...Bye\n");


    getchar();
    return 0;
}
