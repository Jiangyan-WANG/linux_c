#include <stdio.h>
#include <pthread.h>
       #include <unistd.h>

void * do_work(void *msg)
{

    for(int i=0; i<10;i++)
    {
    
        sleep(1);
 
    printf("hello: %s\n",(char*) msg);
   }
    return NULL;
}

int main()
{

    pthread_t ctid;

    char msg[32]="wjy and shuishui";

    int ret = pthread_create(&ctid, NULL, do_work, msg);

    printf("[thread id] %ld\n", ctid);

getchar();
    return 0;
}
