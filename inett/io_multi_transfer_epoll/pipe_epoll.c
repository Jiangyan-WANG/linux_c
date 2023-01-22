#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>

#include <strings.h>

int main()
{

    int fds[2];
    pipe(fds);

    int cpid = fork();

    if(cpid==0)
    {
    
        //child
        close(fds[0]);

        while(1)
        {
        
            sleep(1);
            write(fds[1],"hello\n",5);
        }

        close(fds[1]);

        exit(0);
    }
    else
    {
    
        int epfd = epoll_create(1);
        //father

        struct epoll_event event;

        event.data.fd=fds[0];
        event.events=EPOLLIN;

        epoll_ctl(epfd,EPOLL_CTL_ADD,fds[0],&event);

        struct epoll_event events[1];

        while(1)
        {
            int n = epoll_wait(epfd,events,1,-1);
            if(0==n)
            {
            
                continue;
            }
            else if(-1==0)
            {
            
                perror("epoll_wait:");
            }
            else
            {
            
                for(int i=0; i<n;i++)
                {
                 char buf[1024];
                 bzero(buf,sizeof(buf));
                int n = read(events[i].data.fd,  &buf, sizeof(buf));
                printf("[Read %d bytes] %s\n", n,buf);
            
                }
               }
        }

        close(fds[0]);
        return 0;

        
    }
}
