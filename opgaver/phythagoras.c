#include <stdio.h>  
#include <math.h>

int main(void){
	double side1, side2;

	printf("Please give the two sides of the triangle:\n");
	scanf("%lf %lf", &side1, &side2);
	//printf("Side1: %.4lf \nSide2: %.4lf\n", side1, side2);
	printf("The length of the hypotenuse is %.4lf\n", sqrt(side1*side1 + side2*side2));	

}