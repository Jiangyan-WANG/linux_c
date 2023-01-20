#include <pthread.h>
#include <stdio.h>
 #include <sys/types.h>
       #include <unistd.h>

int main()

{



    pid_t spid = getpid();
    pthread_t stid = pthread_self();

    printf("[process id] %d [thraed id] %ld\n", spid,stid);

        if(pthread_equal(stid,pthread_self()))
        {
        
            printf("equal\n");
        }
        else
        {
        
            printf("not eauql\n");
        }

        return 0;
}


