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

    pthread_t ctid=-1;

    char msg[32]="wjy";

    pthread_attr_t attr;

    //init attr

    pthread_attr_init(&attr);

    //set attr

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    int ret = pthread_create(&ctid, &attr, do_work, msg);

    printf("[thread id] %ld\n", ctid);

    //destory attr
    pthread_attr_destroy(&attr);

    // will failed
    ret = pthread_join(ctid, NULL);
    if(0!=ret)
    {
        printf("thread join failed...\n");
    }
    else
    {
        printf("thread join success...\n");
   }

getchar();
    return 0;
}
