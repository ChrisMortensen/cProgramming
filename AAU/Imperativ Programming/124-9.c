#include <stdio.h>

int main(void){

	double yardWidth, yardLength, houseWidth, houseLength;
	// 9 sqare feet pr. sqare yard at 2 sqare feet a sec is 2/9 sqare yards a sec
	double cuttingSpeed = 9.0/2.0;

	printf("Please give me the width and lenght of your yard.\n");
	scanf("%lf %lf", &yardWidth, &yardLength);

	printf("Please give me the width and lenght of your house.\n");
	scanf("%lf %lf", &houseWidth, &houseLength);
	printf("It will take %.1lf minutes to cut the grass.\n", (cuttingSpeed * (yardLength * yardWidth - houseLength * houseWidth))/60.0);

	return 0;
}