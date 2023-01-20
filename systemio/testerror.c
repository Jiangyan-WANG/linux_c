#include <stdio.h>
#include <string.h>
#include <errno.h>


int main()
{
//    char fname[128]="";

  //  gets(fname);
    //gets();

    FILE *fd = fopen("txt","r");
    if(fd==NULL)
    {
        printf("文件打开错误！");
        printf("[errorno:%d]",errno);
        printf("[%s]",strerror(errno));
        perror("file open failed");
        return 1;
    }
    printf("打开成功! ");
    return 0;
}
