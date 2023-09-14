#include <stdio.h>

int main(void){

	int hours, minutes;

	printf("Please provide the elapsed time since power failure in hours and minutes:\n");
	scanf("%d %d", &hours, &minutes);

	float elapsedTime = minutes / 60.0 + hours;
	printf("The estimated temperature of your fridge is %.2f degrees celcius", ((4.0 * elapsedTime * elapsedTime) / (elapsedTime + 2.0)) - 20.0);

	return 0;
}