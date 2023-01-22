#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <event.h>
#include "wrap.h"

typedef struct info
{
    struct event *evs[1024];
    struct event_base * base;
} INFO;

void msg_read(evutil_socket_t cfd, short events, void * args)
{
    struct event **evs = (struct event **) args;

    char buf[1500];

    bzero(buf,1500);

    int n = Read(cfd, buf, 1500);

    if(n<=0)
    {
        printf("start delete %d\n", cfd);
      event_del(*(evs+cfd));
    event_free(*(evs+cfd));
  close(cfd);  
    }
    else
    {
    
        printf("[Read %d] %s\n", n, buf);
    }

}


void cfd_add(evutil_socket_t sfd, short events, void * args)
{

    INFO * info = (INFO*) args;
    //if not interested in the client address and port, set the params to NULL
    int cfd = Accept(sfd, NULL, NULL);

    struct event *  ev = event_new(info->base, cfd, EV_READ | EV_PERSIST, msg_read, info->evs);

    event_add(ev,NULL);

    info->evs[cfd] = ev;
}
int main()
{

    // socket
    // bind
    int sfd = tcp4bind(8080, NULL);
    // listen
    Listen(sfd, 128);
    // accept
    // create event base---root
    struct event_base *  base = event_base_new();

    INFO * info = malloc(sizeof(INFO));;
    bzero(info, sizeof(INFO));
    //init node

    info->base = base;
    struct event * ev = event_new(base, sfd, EV_READ | EV_PERSIST, cfd_add, info);
 
   info->evs[sfd] = ev;

   //add to tree
   event_add(ev, NULL);

   // listen loop
   event_base_dispatch(base);


   // leave tree
   event_del(info->evs[sfd]);

   event_free(info->evs[sfd]);
   //close
   close(sfd);


   //free
   event_base_free(base);

   free(info);

   return 0;
}
