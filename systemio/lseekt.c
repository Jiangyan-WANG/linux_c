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
    //fd = open("a.txt",O_RDWR | O_CREAT | O_EXCL, 0644);
    fd = open("a.txt",O_RDWR | O_CREAT, 0644);

    if(fd==-1)
    {

        perror("open fail");
        return -1;
    }

    printf("open success");

    write(fd,"hello world",11);


    lseek(fd,32,SEEK_SET);
    write(fd,"123456789",9);


    lseek(fd,0,SEEK_SET);

    char buf[128]="";
    int flagr = read(fd,buf,128);
    printf("read %d:%s",flagr,buf);


    close(fd);
    return 0;
}
