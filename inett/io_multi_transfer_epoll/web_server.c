#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>
#include <signal.h>
#include "wrap.h"
#include <pthread.h>
#include <sys/epoll.h>

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Please input a port number in format like:\n");
        printf("./web_server 8080\n");
        return 0;
    }
    // listenning socket
    int lfd = tcp4bind(atoi(argv[1]),NULL);
    //int sfd = tcp4bind(8080,"0.0.0.0");

    Listen(lfd,128);


    int epfd = epoll_create(1);

    struct epoll_event event;

    event.data.fd=lfd;
    event.events=EPOLLIN;

    epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &event);

    struct epoll_event events[1024];

    while(1)
    {

        int n=epoll_wait(epfd, events, 1024, -1);

        //printf("__________________epoll___________________\n");

        if(n<0)
        {
        
            perror("epoll_wait");

        }
        else if(0==n)
        {
        
            continue;
        }

        else
        {
        
            for(int i=0; i<n;++i)
            {
            
             // check lfd
            if(events[i].data.fd==lfd && events[i].events & EPOLLIN)
            {
                printf("lfd touched...\n");

                struct sockaddr_in caddr;

                socklen_t csize=sizeof(caddr);
                int cfd = Accept(lfd,(struct sockaddr *) &caddr, &csize);

                event.data.fd = cfd;
                event.events=EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &event);
               }

            else if(events[i].events & EPOLLIN)
            {
                 //printf("client [%d] message...\n", events[i].data.fd);
                    
                    //char buf[1500];
                    //modify the buffer size
                    char buf[4];
                    bzero(buf,sizeof(buf));

                    int retlen = Read(events[i].data.fd,buf,sizeof(buf));

                    if(retlen == 0)
                    {
                    
                        printf("%d exit...\n",events[i].data.fd);
                        close(events[i].data.fd);
                        epoll_ctl(epfd, EPOLL_CTL_DEL,events[i].data.fd, &events[i]);

                    }
                    else
                    {

                    //printf("[Read %d bytes] %s", retlen, buf);

                        write(STDOUT_FILENO, buf, 4);
                    }



            }

            
            }
        }
    }
        
    return 0;
}
