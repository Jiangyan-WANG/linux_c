#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
int check()
{

    int status=-1;
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
    printf("[cpid] %d ",ret);
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
    return ret;

}

void work1()
{
    sleep(1);
    char * argvs[]={"ps", "-au", NULL};
    execvp("ps",argvs);

    printf("will not come here");

    return;
}

void work2()
{

    sleep(2);
    char * argvs[]={"./test", NULL};
    execvp("./test",argvs);
    return;
}

void work3()
{
    sleep(12);
    char * argvs[]={"goout", NULL};
    execvp("cp",argvs);
    return;
}

int main()
{


    int count=3;
    int pid1 = fork();
    if(pid1<0)
    {
        perror("fork");
        return 1;
    }

    if(pid1==0)
    {

        work1();
        exit(0);
    }

    int pid2 = fork();
    if(pid2<0)
    {
        perror("fork");
        return 1;
    }

    if(pid2==0)
    {

        work2();
        exit(0);
    }


    int pid3 = fork();
    if(pid3<0)
    {
        perror("fork");
        return 1;
    }

    if(pid3==0)
    {

        work3();
        exit(0);
    }


        //父进程       

    while(1)
    {
    
        sleep(5);
        int ret=check();

        if(ret>0)
        {
            if(--count==0)
            {
         
            printf("check over, exit...\n");
            break;
            
            }
       }
    }
    return 0;
}
