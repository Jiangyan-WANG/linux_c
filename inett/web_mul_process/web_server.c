#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>
#include <signal.h>
#include "wrap.h"
#include <sys/wait.h>

void free_child(int signum)
{

    while(1)
    {
        int cpid = waitpid(-1, NULL, WNOHANG);
        if(cpid<=0)//0 no child exit <0 error
    
        {
        
            break;
        }
        else
        {
        
            printf("[child pid] %d freed..\n", cpid);
        }
    }
}

int main()
{

    // block SIGCHLD before register func
    sigset_t set;
    sigemptyset(&set);

    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK, &set, NULL);
    //block over

    int sfd = tcp4bind(8080,NULL);
    //int sfd = tcp4bind(8080,"0.0.0.0");

    Listen(sfd,128);

    struct sockaddr_in caddr;
    socklen_t csize = sizeof(caddr);

    while(1)
    {
    
        int cfd = Accept(sfd, (struct sockaddr * ) &caddr, &csize); 

        int cpid = fork();
        if(0==cpid)
        {
        
            char ip[16] = "";
            printf("[ip] %s [port] %hu\n", 
                    inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ip, 16), ntohs(caddr.sin_port)
                    );
            //close listen fd in child process
            close(sfd);
            //child process

            char buf[1024];

            while(1)
            {
        

                bzero(buf, sizeof(buf));
                int n = Read(cfd, buf, 1024);
                
                if(0==n)
                {
    printf("[%s] exit...\n",ip);                
                    close(cfd);
                    exit(0);
                }
                printf("%s [read %d] %s\n",ip, n, buf);
                Write(cfd, buf, strlen(buf));

            }

        }

        else
        {
        
            //father process 
    
            close(cfd);

            //restore child process
        
            // signal func set

            struct sigaction act;
            act.sa_handler = free_child;
            act.sa_flags = 0;

            sigemptyset(&act.sa_mask);

            // register func
            sigaction(SIGCHLD, &act, NULL);


            //unblock signal SIGCHLD
            sigprocmask(SIG_UNBLOCK, &set, NULL);
        }
    }
    return 0;
}
