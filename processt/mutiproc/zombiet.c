#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    int pid = fork();
    if(-1==pid)
    {
    
        perror("fork");
        return 1;
    }
    if(0==pid)

    {
    
        for(int i=0;i<5;i++)
        {
        
            sleep(1);
            printf("child do %d\n", i);
        }

        printf("child exit");
        exit(0);
    }

    //阻塞等待，此时子进程变成僵尸进程
    getchar();
    //结束时自动回收
    return 0;
}
