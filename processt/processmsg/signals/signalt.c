//#define _POSIX_C_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>

int main()
{

    int cpid = fork();

    if(cpid==0)

    {
    
        //child
        for(int i=0;i<20;i++)
        {
        
            sleep(1);
            printf("child working ... %d\n",i);
        }
    }
    else 
    {
    
        //father
        //
        sleep(3);
        //stop child
        kill(cpid, SIGSTOP);
        sleep(7);
        //continue child
        kill(cpid, SIGCONT);
        //wait child finish
        wait(NULL);
    }

    return 0;
}
