#include <stdio.h>


void main(){

	double min,max,inches;

	printf("Please provide the interval in the form of two numbers:\n");
	scanf("%lf %lf",&min,&max);
	
	printf("Centimeters : Inches\n");

	for (double i = min; i < max; i+=10)
	{
		inches = i * 0.3937;
		printf("%.2lf : %.2lf\n",i,inches);
	}

	return;
}