#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
int main()
{

    DIR * dira=NULL;
    dira = opendir("test");

    if(NULL==dira)
    {
    
        perror("opendir");

        printf("    directory not exist. start creat...");
        mkdir("test",0775);
        dira=opendir("test");
        if(NULL==dira)
        {
        perror("mkdir");
        printf("    creat fail...exet.");
        return -1;
        }

        printf("     creat success...continue...   ");
    }


    while(1)
    {
        struct dirent * p = readdir(dira);
        if(NULL==p)
        {
        
            break;
        }

        printf("  type:%hu  name:%s\n", p->d_type, p->d_name);
    }
    

    closedir(dira);

    return 0;

}
