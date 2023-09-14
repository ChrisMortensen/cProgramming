#include <stdio.h>
#include <math.h>

void main(){

	double x,y,r;
	double distfromMiddle;
	char* awnser;

	printf("Please provide the x and y coordiantes for the point:\n");
	scanf("%lf %lf",&x,&y);

	printf("Please provide radius of the circle:\n");
	scanf("%lf",&r);

	distfromMiddle = sqrt(x*x+y*y);

	if (distfromMiddle<r){
		awnser = "inside";
	} else if (distfromMiddle==r){
		awnser = "on the periphery";
	} else{
		awnser = "outside";
		
	}
	printf("The point is %s of the circle\n",awnser);

	return;
}