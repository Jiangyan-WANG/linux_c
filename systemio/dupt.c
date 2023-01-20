#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <errno.h>

int main()
{

    int fd =open("a.txt", O_WRONLY | O_CREAT);

    if(-1==fd)
    {
    
        perror("open failed");
    }

    int newfd = dup(fd);

    if(-1==newfd)
    {
    
        perror("open new error");
    
    }

    write(fd, "hello", 5);
    write(newfd,"123456",6);

    int newfd2=dup2(fd,4);
    if(-1==newfd2){
    
        printf("newfd2 open fail");
    }

    int flagnf = write(newfd2,"ggggg",5);
    if(-1==flagnf)
    {
    
        printf("newfd2 create and newfd write fail after");
    }
    close(fd);
    close(newfd);
    close(newfd2);



    return 0;
}
