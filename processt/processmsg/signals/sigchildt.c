#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>
#include <sys/time.h>

void restore(int signum)
{
    printf("child exit\n");

    while(waitpid(-1,NULL,WNOHANG)>0)
    {
    
        continue;
    }
}

int main()
{

    struct sigaction act;
    act.sa_handler=restore;

    act.sa_flags=0;

    sigaction(SIGCHLD,&act,NULL);
   

    int cpid = fork();

    printf("[child pid] %d\n",cpid);

    if(cpid==0)
    {
    
        for(int i=0; i<10;i++)
        {
    sleep(1);        
           printf("child working....\n");
        }
    
        exit(0);
    }

    while(1)
    {
    
        sleep(1);
        printf("working....\n");
    }
   return 0;
}
