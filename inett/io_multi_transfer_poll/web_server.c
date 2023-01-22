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
#include <poll.h>
/*
void * thread_work(void * arg)
{

      
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
*/

#define SIZE 1024

void insert(int fd, struct pollfd * fds, int * size)
{

    if(*size<SIZE)
    {
        fds[*size].fd=fd;
        fds[*size].events=POLL_IN;
        (*size)++;
    }
    else
    {
    
        printf("array full...\n");
    }

}

void delete(int index, struct pollfd *fds, int * size)
{

    if(index<*size)
    {
        fds[index].fd = fds[*size].fd;
    
        fds[*size].fd = -1;

        (*size)--;
    }
    else
    {
    
        fds[index].fd = -1;
        (*size)--;
    }
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

    // poll array
    struct pollfd fds[SIZE];

    // init
    for(int i=0;i<SIZE;i++)
    {
    
        fds[i].fd = -1;
        //fds[i].events = POLLIN;
        //fds[i].revents = 0;
    }

    int size = 0;

    insert(lfd,fds,&size);

    while(1)
    {

        int n = poll(fds, size+1,-1);
             
        if(n<0)
        {
        
            perror("poll");

        }
        else if(0==n)
        {
            continue;
        }

        else
        {
            int len = size;
            int mark[SIZE]={0};
            int markNum=0;
            // check lfd
            for(int i=0;i<=len;i++)
            {
                if(fds[i].fd == lfd && fds[i].revents & POLL_IN)
                {
             
                printf("lfd touched...\n");

                struct sockaddr_in caddr;

                socklen_t csize=sizeof(caddr);
                int cfd = Accept(lfd,(struct sockaddr *) &caddr, &csize);

                insert(cfd,fds,&size);

                if(--n==0)
                {
                
                    continue;
                }
    

                }

                else if(fds[i].revents & POLL_IN)
                {
                    printf("client [%d] message...\n", fds[i].fd);
                    
                    char buf[1500];
                    bzero(buf,sizeof(buf));

                    int retlen = Read(fds[i].fd,buf,1500);

                    if(retlen == 0)
                    {
                    
                        printf("%d exit...\n",fds[i].fd);
                        close(fds[i].fd);
                        mark[markNum++]=i; 
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

            for(int i = 0;i < markNum; i++)
            {
            
                delete(mark[i], fds, &size);
            }
        }


    }

    return 0;
}
