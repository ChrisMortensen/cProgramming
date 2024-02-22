#include <stdio.h>
#define PI 3.14159

double circumference(double);
double area(double);

void main(){
	double radius;
	int choice;
	printf("What is the radius of the circle?\n Radius : ");
	scanf(" %lf", &radius);
	
	printf("Do you want to calculate the area(1), circumference(2) or both(3)?\n");
	scanf(" %d", &choice);

	switch (choice)
	{
	case 1:
		printf("Circumference : %lf\n", circumference(radius));
		break;
	case 2:
		printf("Area : %lf\n", area(radius));
		break;
	case 3:
		printf("Circumference : %lf\n", circumference(radius));
		printf("Area : %lf\n", area(radius));
		break;
	default:
		printf("ERROR! (INVALID INPUT)\n");
		break;
	}
	
	return;
}

double area(double r){
	return PI*r*r;
}

double circumference(double r){
	return r * PI * 2;
}
