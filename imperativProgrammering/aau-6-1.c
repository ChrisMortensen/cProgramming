#include <stdio.h>

void celciusToFahrenheit(float *temp);

int main(void){
	float temp;
	printf("Enter the temperature you want to convert from celcius to fahrenheit.\n");
	printf("Celcius : ");
	scanf(" %f", &temp);
	celciusToFahrenheit(&temp);
	printf("Fahrenheit : %6.2f",temp);
  return 0;
}

void celciusToFahrenheit(float *temp){
	*temp=9.0 / 5.0 * (*temp) + 32.0;
} 
