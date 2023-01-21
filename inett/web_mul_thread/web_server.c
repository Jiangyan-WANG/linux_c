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
    int sfd = tcp4bind(atoi(argv[1]),NULL);
    //int sfd = tcp4bind(8080,"0.0.0.0");

    Listen(sfd,128);

    // set detach of thread
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


    pthread_t tid;
    while(1)
    {

        INFO * info = malloc(sizeof(INFO));
        socklen_t csize = sizeof(info->caddr);

        info->cfd  = Accept(sfd, (struct sockaddr * ) & (info->caddr), &csize); 

       pthread_create(&tid, &attr, thread_work, info); 
           printf("connect successfully...continue listenning...\n");      
       }

    return 0;
}
