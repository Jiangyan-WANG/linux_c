#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>

int main()
{


    int csid = getsid(0);

    printf("[current session id] %d\n",csid);

    int cpid = fork();

    if(cpid ==0)
    {
 
    int ret = setsid();

    if(-1==ret)
    {
    
        perror("setsid:");
        return 1;
    }

    csid = getsid(0);

    printf("[current session id] %d\n",csid);

    sleep(3000);
   
    }



    getchar();

    return 0;

}
