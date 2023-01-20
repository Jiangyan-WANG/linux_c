#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
       #include <stdio.h>
#include <wait.h>

#define SIZE 1024

int main()
{

    //open file

    int fd = open("a.txt", O_RDWR);

    if(-1==fd)
    {
    
        perror("open:");
        return 1;
    }

    //mapping
    void * addr = NULL; 
    addr  = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    //check error
    if(addr==MAP_FAILED)
    {
    
        perror("mmap:");
            return 1;
    }

    printf("mapping success...\n");    
    //close file


    int cpid = fork();

    if(cpid==0)
    {
    //child process write;

    //memory write - memcpy
    memcpy(addr, "1234567890",10);
    }
    else
    {
    //father process read
    //wait for child exit
    wait(NULL);

printf("%s\n",(char*)addr);
    }

    //unmap
    munmap(addr,SIZE);

    close(fd);
    return 0;

    
}
