#include <stdio.h>
#include <math.h>


int main(void){
	double NG, N, LG = 1.0;
	
	printf("Provide the number you want to find the sqare root of.\n");
	printf("Number : ");
	scanf(" %lf", &N);

	while(1){
		NG = 0.5*(LG + N/LG);
		if(abs(NG-LG) > 0.005){
			LG=NG;
		} else {
			break;
		}
	}
	printf("Square root : %lf", NG);

	return 0;
}