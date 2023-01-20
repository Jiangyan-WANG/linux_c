#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

    printf("%d %d %d", getpid(), getppid(), getpgid(getpid()));

    return 0;

}
