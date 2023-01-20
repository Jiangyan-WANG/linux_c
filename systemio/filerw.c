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

    close(fd);
    return 0;
}
