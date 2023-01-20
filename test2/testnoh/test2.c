#include <stdio.h>

///不需要包含头文件，只要有库就可以用
int main()
{

	int a=10;
	int b=5;
	printf("%d %d %d %d ", add(a,b),sub(a,b),mul(a,b),div(a,b));
	// desire 15,5,50,2
	return 0;
}
