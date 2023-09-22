#include <stdio.h>
#include <math.h>

void main(){

	double x,y,r;
	double distfromMiddle;
	char* anwser;

	printf("Please provide the x and y coordiantes for the point:\n");
	scanf("%lf %lf",&x,&y);

	printf("Please provide radius of the circle:\n");
	scanf("%lf",&r);

	distfromMiddle = sqrt(x*x+y*y);

	if (distfromMiddle<r){
		anwser = "inside";
	} else if (distfromMiddle==r){
		anwser = "on the periphery";
	} else{
		anwser = "outside";
	}
	printf("The point is %s of the circle\n",anwser);

	return;
}