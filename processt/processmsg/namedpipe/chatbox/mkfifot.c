#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    
    if(argc < 2)
    {
    
        printf("请输入管道名!\n");
        return 0;
    }


    //判断管道是否存在
    if(access(argv[1], F_OK)!=0)
    {
    
        int ret = mkfifo(argv[1],0644);

        //创建管道出错处理
        if(ret == -1)
        {
        
            perror("mkfifo:");
            return 1;
        }
    }
    else
    {
    
    printf("管道已存在...\n");
    }

    return 0;
}
