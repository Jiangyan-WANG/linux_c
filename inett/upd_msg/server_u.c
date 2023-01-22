#include <sys/socket.h>
 #include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{

    int sfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8888);
    saddr.sin_addr.s_addr = inet_network("0.0.0.0");
    
    //bind local address

    bind(sfd, (struct sockaddr * )&saddr, sizeof(saddr));

    struct sockaddr_in caddr;
    socklen_t csize = sizeof(caddr);

    char buf[1500];
    char ip[16];
    while(1)
    {
        bzero(buf,sizeof(buf));
        bzero(ip,sizeof(ip));
    

        int n = recvfrom(sfd, &buf, sizeof(buf), 0, (struct sockaddr *) &caddr, &csize);

        printf("[recvfomr] ip: %s port: %d\n", 
                inet_ntop(AF_INET, &(caddr.sin_addr.s_addr),ip,16),
                ntohs(caddr.sin_port)
                );
        
        printf("[msg] %s\n", buf);

    }

    close(sfd);
    return 0;
}
