#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main()
{

	int a=10;
	int b=5;
	printf("%d %d %d %d ", add(a,b),sub(a,b),mul(a,b),div(a,b));
	// desire 15,5,50,2
	return 0;
}
