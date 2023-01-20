#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <errno.h>

int main()
{

    int fd =open("a.txt", O_WRONLY | O_CREAT, 0644);

    if(-1==fd)
    {
    
        perror("open failed");
    }

    int newfd=fcntl(fd,F_DUPFD, 5);


    if(-1==newfd)
    {
    
        perror("open new error");
    
    }

    printf("%d %d ",fd,newfd);



    //修改文件状态标记
    int ret = fcntl(fd,F_GETFL);

    fcntl(fd,F_SETFL,ret | O_APPEND);

    write(fd, "hello", 5);
    write(newfd,"123456",6);

    close(fd);
    close(newfd);

    return 0;
}
