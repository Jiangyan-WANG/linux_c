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
    return (void *) 0x3;
}

int main()
{

    pthread_t ctid;

    char msg[32]="wjy and shuishui";

    int ret = pthread_create(&ctid, NULL, do_work, msg);

    printf("[thread id] %ld\n", ctid);

    void * flag=NULL;


    printf("blocked...\n");
    //blocked
    pthread_join(ctid, &flag);

    printf("unblocked...\n");

    getchar();

    //if child already return, will not blocked
    //pthread_join(ctid, &flag);

    printf("receive child thread exit: %p\n", flag);

    return 0;
}
