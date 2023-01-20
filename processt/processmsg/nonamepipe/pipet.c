#include <stdio.h>
#include <unistd.h>

int main()
{
    int fds[2]={0};

    pipe(fds);

    printf("fd:%d for read, fds:%d for write\n",fds[0],fds[1]);

    close(fds[0]);
    close(fds[1]);
}
