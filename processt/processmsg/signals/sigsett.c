//#define _POSIX_C_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>


void show_set(sigset_t * set)
{

    for(int i=1;i<32;i++)
    {
        if(sigismember(set,i)==0)
        {
     
            printf("0");   
        }
        else
        {
        
            printf("1");
        }

    }
    printf("\n");

}

int main()
{

    sigset_t set;

    sigemptyset(&set);

    show_set(&set);


    sigfillset(&set);
    show_set(&set);

    sigemptyset(&set);

    sigaddset(&set, SIGINT);
    sigaddset(&set,SIGQUIT);
    show_set(&set);

    sigdelset(&set, SIGINT);
    show_set(&set);



    return 0;
}
