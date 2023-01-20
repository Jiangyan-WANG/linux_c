#include <stdio.h>
#include "swap.h"

int main()
{
    int a = 10;
    int b = 30;
    printf("before: %d %d ", a, b);
    swap(&a, &b);
    printf("after: %d %d ", a, b);
    return 0;
}
