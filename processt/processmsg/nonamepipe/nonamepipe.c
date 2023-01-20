#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
        
        memset(buf,0,SIZE);

        read(fds[0],buf,SIZE);

        //无须换行
        printf("[child,%d] READ: %s",getpid(),buf);


        close(fds[0]);
        exit(0);
    }


    //printf("fd:%d for read, fds:%d for write\n",fds[0],fds[1]);

    close(fds[0]);


    char buf[SIZE];
    memset(buf,0,SIZE);


    sleep(1);
    printf("[parent,%d)] WRITE: ",getpid());
    fgets(buf,SIZE,stdin);
    //printf("%s\n", buf);

    //write(fds[1],"hello world!\n",12);
    write(fds[1],buf,strlen(buf));

    close(fds[1]);

    //等两秒
    sleep(1);
    return 0;
}
