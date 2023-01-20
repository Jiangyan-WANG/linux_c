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

    sigset_t set;
    sigset_t old;
    sigemptyset(&set);
    sigemptyset(&old);
   signal(SIGINT, dowork);


   sigaddset(&set, SIGINT);

   printf("press ENTER to BLOCK\n");


   getchar();

   sigprocmask(SIG_BLOCK, &set, &old);

   printf("press ENTER to UNBLOCK\n");
   

   getchar();

    sigprocmask(SIG_UNBLOCK, &set, &old);

   getchar();
   
   return 0;
}
