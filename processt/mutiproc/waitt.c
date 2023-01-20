#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{


    int childP = fork();

    if(childP<0)
    {
    
        perror("fork");
        return 1;
    }

    if(childP==0)
    {
    
        //子进程
        

        int curP = getpid();

        for(int i=0;i<15;++i)
        {
        
            sleep(1);
    // 父进程退出后子进程会变成孤儿进程，被1号进程收养
            printf("[%d] child work %d, [father:%d]\n",curP, i, getppid());

        }
        exit(10);
    }


    int status=0;
    //sleep(20);
    //wait(&status);

    //等价于wait
    //int ret=waitpid(-1,&status,0);
    //sleep(20);
    sleep(3);
    //不阻塞
    int ret=waitpid(-1,&status,WNOHANG);
    
    if(-1==ret)
    {
    
        perror("wait");
        return 1;
    }

    if(0==ret){
    

    printf("ret:%d\n",ret);
    }

    else
    {
    if(WIFEXITED(status)!=0)
    {
    
        printf("exit normally: %d\n", WEXITSTATUS(status));
    }

    if(WIFSIGNALED(status)!=0)
    {
    
        printf("signal exit: killed by %d\n", WTERMSIG(status));
    }
    if(WIFSTOPPED(status)!=0)
    {
    
        printf("stoped:%d\n",WSTOPSIG(status));
    }

    }


    return 0;



}
