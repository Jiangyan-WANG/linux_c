#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <sys/types.h>
       #include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#define SIZE 128

int main()
{

    int fd = open("b.txt",O_RDWR | O_CREAT,0664);

    int cpid = fork();

    if(0==cpid)
    {

        write(fd,"helloworld",10);
        exit(0);
    }


    char buf[SIZE] = "";


    sleep(1);
    lseek(fd,0,SEEK_SET);
    read(fd,buf,sizeof(char)*SIZE);
    printf("%s\n",buf);
    return 0;
}
