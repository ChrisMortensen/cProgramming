#include <stdio.h>

int main(void)
{
	int iterations = 0;
	printf("Iterations: ");
	scanf(" %d", &iterations);
	double result = 0;
	int posOrNeg = 1;
	for (int i = 1; i <= iterations; i++)
	{
		result+=posOrNeg*(1.0/(2.0*i-1.0));
		posOrNeg*=-1;
	}
	double pi = 4 * result;
	printf("Pi is %lf", pi);
	return 0;
}