#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define SIZE 32

int main()
{

    //有名管道操作类似文件
    int fd = open("fifo",O_RDONLY);

    //循环读
    char buf[SIZE];

    while(1)
    {
        memset(buf,0,SIZE);
        int ret = read(fd, buf, SIZE);

        if(ret==0)
        {
        
            printf("发送端已关闭\n");
            return 0;
        }
        printf("[read] %s\n",buf);
    }

    //关闭
    close(fd);

    return 0;
}
