#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <error.h>

int main()
{

    char buf[32];
    memset(buf,0,32);
    if(NULL==getcwd(buf,32))
    {
    
        perror("getcwd");
    }

    printf("old:%s     ",buf);

    chdir("/home/wjy");

    memset(buf,0,32);
    getcwd(buf,32);

    printf("%s", buf);
    return 0;
}
