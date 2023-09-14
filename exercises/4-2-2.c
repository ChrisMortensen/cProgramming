#include <stdio.h>

void main(){

	int a = 6, b = 9, c = 14, flag = 1;

	printf("Awnsers:\n%d\n%d\n%d\n%d\n",
	c == a + b || !flag,
	a != 7 && flag || c >= 6,
	!(b <= 12) && a % 2 == 0,
	!(a > 5 || c < a + b));

}