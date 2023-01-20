#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{

    printf("hello\n");

    //execlp进程切换后，完全切换成新进程的内存状态，
    //并执行新进程的main函数，因此execlp后的内容不
    //会执行
   // execlp("ls","ls","-la",NULL);

    char * argvs[]={"ls", "-la", "/home", NULL};
    execv("/bin/ls",argvs);


    printf("will not come here");
    return 0;
}
