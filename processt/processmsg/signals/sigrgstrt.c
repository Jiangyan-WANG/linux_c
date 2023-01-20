//#define _POSIX_C_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>
#include <sys/time.h>

void dowork(int signum)
{

    printf("hello world!\n");
}

int main()
{
    struct timeval start = {5, 0};
    struct timeval step = {2, 0};

    struct itimerval timer={step,start};

    setitimer(ITIMER_REAL, &timer, NULL );

    getitimer(ITIMER_REAL,&timer);
    signal(SIGALRM, dowork);


    for(int i=0;i<20;i++)
        {


            sleep(1);
            printf("working ... %d\n",i);

        }
    getchar();
            return 0;
}
