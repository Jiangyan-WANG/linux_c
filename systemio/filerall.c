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
    char buf[12];
    fd = open("a.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("open fail");
        return -1;
    }

    printf("open success\n");

    int flagsr = -1;
    int count = 0;
    while(flagsr!=0)
    {
        flagsr = read(fd,buf,sizeof(buf)/sizeof(char)-1);


        if(flagsr==-1)
        {
    
            perror("read error");
            break;
        }
        buf[flagsr]=0;
        //printf("read success:%d\n",flagsr);
        printf("%s",buf);
        count += flagsr;

    }

    printf("[total read:%d]\n", count);
    close(fd);
    return 0;
}
