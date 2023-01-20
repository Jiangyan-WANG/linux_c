#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int varG = 85;

int main()
{

    int varL = 56;

    int pid = fork();


    if(pid<0)
    {
    
        perror("fork");
        return 1;
    }

    if(pid==0)
    {
    
        //子进程
        for(int i=0;i<10;++i)
        {
        sleep(1);
        printf("child: %d %d\n", varG,varL);

        }
    }

    else
    {
    

        //父进程
        for(int i=0;i<10;++i)

        {
        sleep(1);
        varG++;
        varL++;

        printf("father: %d %d\n",varG,varL);
        }
    }


    return 0;
}
