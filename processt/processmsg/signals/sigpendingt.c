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

    sigset_t set;
    sigset_t old;

    sigset_t pend;
    sigemptyset(&set);
    sigemptyset(&old);
    sigemptyset(&pend);
   signal(SIGINT, dowork);


   sigaddset(&set, SIGINT);

   printf("press ENTER to BLOCK\n");


   sigpending(&pend);
   show_set(&pend);

   getchar();

   sigprocmask(SIG_BLOCK, &set, &old);

   printf("press ENTER to UNBLOCK\n");
   

   getchar();

   sigpending(&pend);
   show_set(&pend);

   sigprocmask(SIG_UNBLOCK, &set, &old);

   getchar();
   
   return 0;
}
