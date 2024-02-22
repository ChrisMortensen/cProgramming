#include <stdio.h>
#define PI 3.14159
#define MAX_I 1000


void main(){

	double x, y;
	int a, b, i;

	a=3;
	b=4;
	y=-1.0;

	printf("Test %d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
	i = a % b,
	i = (989 - MAX_I) / a,
	i = b % a,
	x = PI * y,
	i = a / -b,
	x = a / b,
	x = a % (a / b),
	//i = b / 0, Devision by 0
	i = a % (990 - MAX_I),
	i = (MAX_I - 990) / a,
	x = a / y,
	i = PI * a,
	x = PI / y,
	x = b / a,
	i = (MAX_I - 990) % a,
	// i = a % 0, Modulo by 0
	i = a % (MAX_I - 990),
	x = (double) a / b);

	return;
}
