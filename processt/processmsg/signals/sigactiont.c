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


void dowork2(int signum, siginfo_t * sgt, void *vd)
{
    printf("hello world! gogogo fu\n");


    
}

void show_set(sigset_t * set)
{

    for(int i=1;i<32;i++)

    {
    
        if(sigismember(set,i)!=0)
        {
        
            printf("1");
        }
        else
        {
        
            printf("0");
        }
    }
    printf("\n");
}

int main()
{

    struct sigaction act;
    act.sa_sigaction=dowork2;

    act.sa_flags=SA_SIGINFO;

    sigaction(SIGINT,&act,NULL);
   
    while(1)
    {
    
        getchar();
    }
   return 0;
}
