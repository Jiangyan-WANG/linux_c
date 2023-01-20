#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int countFile(char * dir, int * count)
{
    DIR * dira=NULL;
    dira = opendir(dir);

    if(NULL==dira)
    {
        perror("opendir");
        return -1;
    }

    printf("open [%s] success\n",dir);

    struct dirent * finfo=NULL;
    while((finfo = readdir(dira))!=NULL)
        {
        
    //判断是否为文件
    if(finfo->d_type!=DT_DIR){
        (*count)++;
    printf("%s is a file\n", finfo->d_name);
    }
    //判断是否为目录
    else
    {
    printf("%s is a dir\n",finfo->d_name);

    //printf("*****%s*****\n",finfo->d_name);
    if(strcmp(finfo->d_name,".")&&strcmp(finfo->d_name,".."))
    {
    
        printf("****%s****\n",finfo->d_name);

        //拼接新目录
        char newDir[128]="";
        strcpy(newDir,dir);
        strcat(newDir,"/");
        strcat(newDir,finfo->d_name);

        printf("%s\n",newDir);



        countFile(newDir,count);
    }

    }
        } 

    

    closedir(dira);
    return 0;
}

int main(int argc, char * argv[])
{

    int count=0;
    countFile(argv[1], &count);
    printf("总共有 %d 个文件\n",count);
}
