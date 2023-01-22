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
#include <sys/select.h>

typedef struct info
{
    int cfd;
    struct sockaddr_in caddr;
} INFO;


void * thread_work(void * arg)
{

    INFO * info = (INFO *) arg;
      
    char ip[16] = "";
    printf("[ip] %s [port] %hu\n", 
                    inet_ntop(AF_INET, &(info->caddr.sin_addr.s_addr), ip, 16), ntohs(info->caddr.sin_port)
                    );

            char buf[1024];

            while(1)
            {
                bzero(buf, sizeof(buf));
                int n = Read(info->cfd, buf, 1024);
                
                if(0==n)
                {
    printf("[%s] exit...\n",ip);                
                    close(info->cfd);
                    free(info);
                    pthread_exit(0);
                }
                printf("%s [read %d] %s\n",ip, n, buf);
                Write(info->cfd, buf, strlen(buf));

            }

            return NULL;
}

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

    //select implemation of multitransfer
    fd_set oldset;

    //init fd_set and add lfd
    FD_ZERO(&oldset);
    FD_SET(lfd, &oldset);

    // max index in the bitmap of select listenning

    int maxfd = lfd;
    while(1)
    {
        // update read set
        fd_set rset = oldset;

        int n = select(maxfd+1, &rset, NULL, NULL,NULL);

        if(n<0)
        {
        
            perror("select");

        }
        else if(0==n)
        {
        
            continue;
        }

        else
        {
        
            // check lfd
            if(FD_ISSET(lfd,&rset))
            {
            
                printf("lfd touched...\n");

                struct sockaddr_in caddr;

                socklen_t csize=sizeof(caddr);
                int cfd = Accept(lfd,(struct sockaddr *) &caddr, &csize);

                FD_SET(cfd, &oldset);
                maxfd = cfd;
                if(--n==0)
                {
                
                    continue;
                }
            }

            //check other
            for(int cur_fd=lfd+1; cur_fd<=maxfd; ++cur_fd)
            {
            
                if(FD_ISSET(cur_fd, &rset))
                {
                
                    printf("client [%d] message...\n", cur_fd);
                    
                    char buf[1500];
                    bzero(buf,sizeof(buf));

                    int retlen = Read(cur_fd,buf,1500);

                    if(retlen == 0)
                    {
                    
                        printf("%d exit...\n",cur_fd);
                        close(cur_fd);
                        FD_CLR(cur_fd, &oldset);
                        if(cur_fd == maxfd)
                        {
                        
                            maxfd--;
                        }
                    }
                    else
                    {

                    printf("[Read %d bytes] %s\n", retlen, buf);

                    }

                    if(--n==0)
                    {
                    
                        break;
                    }
                }
            }

        }


    }

    return 0;
}
