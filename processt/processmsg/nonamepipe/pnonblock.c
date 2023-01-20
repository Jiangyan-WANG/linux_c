#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 64

int main()
{
    int fds[2]={0};

    pipe(fds);

    int cpid = fork();
    if(0==cpid)
    {
    
        close(fds[1]);

        //查看缓冲区大小
        printf("[readbuf] %ld\n",fpathconf(fds[0],_PC_PIPE_BUF));

        char buf[SIZE];
        

            int flagsr = fcntl(fds[0],F_GETFL);

            flagsr |= O_NONBLOCK;
            fcntl(fds[0],F_SETFL,flagsr);


        for(int i=0;i<5;++i)
        {
        memset(buf,0,SIZE);
            //非堵塞5秒读一次
            sleep(5);
        int len = read(fds[0],buf,SIZE-1);

        //清除末尾的换行

        if(len>0 && buf[len-1]=='\n')
        {
        buf[len-1]=0;
        }

        //换行刷新缓冲区
        printf("[child,%d] READ: %s\n",getpid(),buf);
        }

        close(fds[0]);
        exit(0);
    }


    //printf("fd:%d for read, fds:%d for write\n",fds[0],fds[1]);

    close(fds[0]);


    char buf[SIZE];
    memset(buf,0,SIZE);


    sleep(1);
    printf("[parent,%d)] WRITE: ",getpid());
    fgets(buf, SIZE, stdin);
    //printf("%s\n", buf);
   //write(fds[1],"hello world!\n",12);
    write(fds[1],buf,strlen(buf));

 
    //会读到输入输入的换行

    close(fds[1]);

    //等待子进程结束
    int status = 0;
    wait(&status);
 
    //等两秒
    //sleep(1);
    return 0;
}
