#include <stdio.h>

double multi_apply(int n, double s);
double half(double x);

int main(void)
{
	printf("Result : %.2lf", multi_apply(3, 16));
	return 0;
}

double multi_apply(int n, double s)
{
	s = half(s);
	n--;
	if(n>0){	
		return (multi_apply(n,s));
	}
	return s;
}

double half(double x){
    return x/2;
}