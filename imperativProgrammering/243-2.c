#include <stdio.h>

void main(){
	int watts,lumens;

	printf("Please provide the wattage of the light bulb:\n");
	scanf("%d",&watts);

	if(watts == 15){
		lumens = 125;
	} else if(watts == 25){
		lumens = 215;
	} else if (watts == 40){
		lumens = 500;
	} else if (watts == 60){
		lumens = 880;
	} else if (watts == 75){
		lumens = 1000;
	} else if (watts == 100){
		lumens = 1675;
	} else {
		lumens = -1;
	}

	printf("The brightness of the lightbulb is %d lumens.\n", lumens);

	return;
}