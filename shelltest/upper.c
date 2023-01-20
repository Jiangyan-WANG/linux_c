#include <stdio.h>
#include <crypt.h>

int main(){

    char ltr;
    while((ltr=getchar())!=EOF)
    {
        putchar(toupper(ltr));
    } 
    return 0;
}
