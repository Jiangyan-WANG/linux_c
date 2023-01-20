#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 64

int main(){

    //read
    int rfd = open("fifo2",O_RDONLY);

    //write
    int wfd = open("fifo1",O_WRONLY);


    char bufr[SIZE];

    char bufw[SIZE];

    while(1)
    {
 
        //read loop
        //
        memset(bufr,0,SIZE);
        int ret = read(rfd,bufr,SIZE);

        if(ret==0)
        {
        
            printf("writer closed...");
            return 0;

        }

        printf("[read %d]: %s\n",ret,bufr);

   
        //write loop

        printf("[write]:");

        //get msg from cmd
        fgets(bufw,SIZE,stdin);
        int len = strlen(bufw);
        //remove final enter
        if(bufw[len-1]=='\n')
        {
        
            bufw[len-1]=0;
        }
        write(wfd,bufw,strlen(bufw));
    }




    close(wfd);
    close(rfd);


    return 0;

}
