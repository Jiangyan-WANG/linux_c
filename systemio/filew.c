#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{

    int fd = -1;
    //fd = open("a.txt",O_WRONLY | O_CREAT | O_EXCL, 0644);
    //fd = open("a.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
    //fd = open("a.txt",O_WRONLY | O_CREAT , 0644);
    fd = open("a.txt",O_WRONLY | O_APPEND , 0644);
    if(fd==-1)
    {

        perror("open fail");
        return -1;
    }

    printf("open success");

    char buf[128]="hello world\n";
    int flagw = write(fd, buf, strlen(buf));

    if(flagw==-1)
    {
    
        perror("write failed\n");
    }

    printf("write success:%d\n",flagw);

    close(fd);
    return 0;
}
