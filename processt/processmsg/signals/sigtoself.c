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
       for(int i=0;i<20;i++)
        {

            if(i==8)
            {
            
                abort();
            
                // raise(SIGSTOP);
            }


            sleep(1);
            printf("working ... %d\n",i);

        }
            return 0;
}
