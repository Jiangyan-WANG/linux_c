#include <unistd.h>
#include <stdio.h>

int main()
{

    sleep(2);
    for(int i=0;i<5;i++)
    {
        sleep(2);
    printf("hello man, %d\n",i);
    }
}
