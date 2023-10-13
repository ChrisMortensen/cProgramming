#include <stdio.h>

void add(double, double, double, double, double *, double *);

int main(void)
{
	double u1, u2, v1, v2, w1, w2;

	printf("Please provide 2 vectors.\n"); 
	printf("1st Vector : ");
	scanf(" %lf %lf", &u1, &u2);
	printf("2nd Vector : ");
	scanf(" %lf %lf", &v1, &v2);
	
	add(u1, u2, v1, v2, &w1, &w2);

	printf("Add-Vector : %.2lf,%.2lf",w1,w2);
	return 0;
}

void add(double v1, double v2, double u1, double u2, double *w1, double *w2)
{
	*w1 = v1 + u1;
	*w2 = v2 + u2;
}