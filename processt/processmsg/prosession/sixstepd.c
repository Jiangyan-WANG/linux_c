#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
       #include <sys/stat.h>

int main()
{


    int csid = getsid(0);

    printf("[current session id] %d\n",csid);

    // 1 create child process
    int cpid = fork();

    if(cpid ==0)
    {


       // 2. create session 
    int ret = setsid();


    if(-1==ret)
    {
    
        perror("setsid:");
        return 1;
    }

    csid = getsid(0);

    printf("[current session id] %d\n",csid);

    printf("session created, press any key to finish ... \n");
    // 3. change dir to /
    chdir("/");

    // 4. set file mask umask
    umask(0);

    // 5. close file identifier, should use micro
    close(STDIN_FILENO);//stdin is FILE *
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    /*
    close(0);
    close(1);
    close(2);

    */
    // 6. leave current init controller, use exec to change main
    // here you can use exec to change with your own process
    //sleep(3000);
   
    // a demo tast
    while(1)
    {
    
        system("date>>/tmp/date.log");
        sleep(30);
    }

    }



    getchar();

    return 0;

}
