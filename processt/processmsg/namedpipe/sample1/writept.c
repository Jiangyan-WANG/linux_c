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
    int fd = open("fifo",O_WRONLY);

    //循环写
    char buf[SIZE];
    int i=0;

    while(1)
    {
        //组包

        int ret  = sprintf(buf,"Hello World %d",i++);

        write(fd, buf, strlen(buf));

        printf("[write] %s: %d byte\n", buf, ret);
        sleep(1);
    }

    //关闭
    close(fd);

    return 0;
}
