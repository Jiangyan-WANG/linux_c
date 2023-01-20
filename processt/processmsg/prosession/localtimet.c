#include <time.h>
#include <stdio.h>

int main(){

    time_t t = time(NULL);


    struct tm* localt =  localtime(&t);

    printf("%d-%d-%d %d:%d:%d 星期%d\n",1900+ localt->tm_year, localt->tm_mon+1,
            localt->tm_mday, localt->tm_hour, localt->tm_min, 
            localt->tm_sec, localt->tm_wday);

     return 0;
}
