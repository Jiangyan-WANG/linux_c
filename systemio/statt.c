 #include <sys/types.h>
       #include <sys/stat.h>
       #include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
void getFileType(struct stat * buf)
{

    switch (buf->st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
}
void getFilePermission(struct stat *buf)
{
           
    
    
    if(buf->st_mode & S_IRUSR)
    {
        printf("owner has read permission\n");
    }

    if(buf->st_mode & S_IWUSR)
    {          
        printf("owner has write permission\n");
    }
    if(buf->st_mode & S_IXUSR)
    {
         printf("owner has execute permission\n");
    }
}
int main()
{

    struct stat buf;
    int flagst = stat("a.txt",&buf);
    if(flagst==-1)
    {
    
        perror("stat check fail");
    
        return -1;
    }

    printf("%ld\n", buf.st_dev);

    printf("%ld\n",buf.st_size);
    //显示文件类型
    getFileType(&buf);

    //显示文件权限
    getFilePermission(&buf);
    return 0;

}
