#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int varG = 85;

int main()
{

    int varL = 56;


    //堆区申请
    int *p = malloc(sizeof(int));
    //初始化
    memset(p,0,sizeof(int));

    //在父子进程都要释放
    //valgrind a.out查看内存泄漏情况
    *p=101;

    int pid = fork();


    if(pid<0)
    {
    
        perror("fork");
        return 1;
    }

    if(pid==0)
    {
    
        //子进程
        for(int i=0;i<10;++i)
        {
        sleep(1);
        printf("child: %d %d %d\n",*p, varG,varL);

        }

        free(p);
    }

    else
    {
    

        //父进程
        for(int i=0;i<10;++i)

        {
        sleep(1);
        varG++;
        varL++;

        (*p)++;
        printf("father: %d %d %d\n",*p,varG,varL);
        }

        free(p);
    }


    return 0;
}
