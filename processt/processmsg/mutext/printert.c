#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * fun1(void * arg)
{

    for(char i = 'A';i<'Z';i++)
    {
        usleep(100000);


        printf("%c",i);
        fflush(stdout);
    }
    return NULL;

}

void * fun2(void * arg)
{

    for(char i = 'a';i<'z';i++)
    {
    
        usleep(100000);
        printf("%c",i);
        fflush(stdout);
    }
    return NULL;

}


int main()
{

    pthread_t ctid1;
    pthread_t ctid2;
    memset(&ctid1,0,sizeof(ctid1));
    memset(&ctid2,0,sizeof(ctid2));
    pthread_create(&ctid1, NULL, fun1, NULL);
    pthread_create(&ctid2, NULL, fun2, NULL);

    //restore

    pthread_join(ctid1,NULL);
    
    printf("\n");

    printf("thread 1 resotred...\n");

    pthread_join(ctid2,NULL);
    printf("thread 1 resotred...\n");


    return 0;
}
