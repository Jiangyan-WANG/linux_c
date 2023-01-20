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
    char buf[128];
    fd = open("a.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("open fail");
        return -1;
    }

    printf("open success");

    int flagsr = read(fd,buf,sizeof(buf)/sizeof(char));

    if(flagsr==-1)
    {
    
        perror("read error");
    }

    printf("read success:%d\n",flagsr);
    printf("%s",buf);

    close(fd);
    return 0;
}
