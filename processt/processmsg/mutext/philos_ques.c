#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t choplik[5];
pthread_t phyilos[5];

void * eat(void * arg)
{
    int num1 = (int) arg;
    int num2;
    if(num1==4)
    {
        num2=0;
    }
    else
    {
    
        num2 = num1+1;
    }

    while(1)
    {
    pthread_mutex_lock(choplik+num1);
    pthread_mutex_lock(choplik+num2);

    printf("[%d] is eating...\n", num1);

    pthread_mutex_unlock(choplik+num2);
    pthread_mutex_unlock(choplik+num1);
    usleep(1000000);
    }
}

int main()
{

    for(int i=0;i<5;i++)
    {
        pthread_mutex_init(choplik+i,NULL);
    }

    for(int i=0;i<5;i++)
    {

        pthread_create(phyilos+i,NULL,eat,(void *)i);
    }


    for(int i=0;i<5;i++)
    {

        pthread_join(*(phyilos+i),NULL);
    }





    for(int i=0;i<5;i++)
    {
        pthread_mutex_destroy(choplik+i);
    }


    return 0;


}
