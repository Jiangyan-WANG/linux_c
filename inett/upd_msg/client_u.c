#include <sys/socket.h>
 #include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
 #include <unistd.h>

int main()
{

    int cfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8888);
    saddr.sin_addr.s_addr = inet_addr("192.168.54.2");
    
    //connect local address

    char buf[1500];
    char ip[16];
    while(1)
    {
        bzero(buf,sizeof(buf));
        bzero(ip,sizeof(ip));
    
        read(STDIN_FILENO, &buf, sizeof(buf));

        int n = sendto(cfd, &buf, strlen(buf), 0, (struct sockaddr *) &saddr, sizeof(saddr)); 

        printf("[sendto] ip: 192.168.54.2 port: 8888\n");
        
        printf("[msg] %s\n", buf);

    }

    close(cfd);
    return 0;
}
