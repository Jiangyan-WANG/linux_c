#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{

    unlink("sock.c");
    //socket
    int cfd = socket(AF_UNIX, SOCK_STREAM, 0);
    //bind, don't use sizeof ifpossible to avoid calculation
    struct sockaddr_un caddr;
    caddr.sun_family = AF_UNIX;
    strcpy(caddr.sun_path, "sock.c");
    bind(cfd,(struct sockaddr *)&caddr,sizeof(caddr));
    //connect
    struct sockaddr_un saddr;
    saddr.sun_family=AF_UNIX;
    strcpy(saddr.sun_path,"sock.s");
    connect(cfd,(struct sockaddr * )&saddr,sizeof(saddr));
    //
    while(1)
    {
    
        char buf[1024];
        bzero(buf,1024);


        int ret = read(STDIN_FILENO, buf, 1024);

        int n = send(cfd, &buf, ret, 0);
        
            printf("[SENT %d] %s\n", n, buf);
        
    }
    //close
    //
    close(cfd);
    return 0;
}
