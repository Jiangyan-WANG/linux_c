#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main()
{


    int csid = getsid(0);

    printf("[current session id] %d\n",csid);


    getchar();

    return 0;

}
