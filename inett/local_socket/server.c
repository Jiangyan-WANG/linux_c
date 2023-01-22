#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{

    unlink("sock.s");
    //socket
    int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    //bind, don't use sizeof ifpossible to avoid calculation
    struct sockaddr_un saddr;
    saddr.sun_family = AF_UNIX;
    strcpy(saddr.sun_path, "sock.s");
    bind(sfd,(struct sockaddr *)&saddr,sizeof(saddr));
    //listen
    listen(sfd,128);
    //accept
    //
    while(1)
    {
    
        char buf[1024];
        bzero(buf,1024);

        int cfd = accept(sfd, NULL, NULL);
        int n = recv(cfd, &buf, 1024, 0);
        if(n<=0)
        {
        
            close(cfd);
        }
        else
        {
        
            printf("[Read %d] %s\n", n, buf);
        }
    }
    //close
    //
    close(sfd);
    return 0;
}
