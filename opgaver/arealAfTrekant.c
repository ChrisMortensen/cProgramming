#include <stdio.h>  

int main(void){
	
	double width, height;
	
	printf("Skriv grundlinjen efterfuldt af hojden for at fa arealet af en trekant:\n");
	scanf("%lf %lf", &width, &height);
	printf("Det vil sige at arealet af trekanten er %lf", 0.5 * width * height);
	return 0;
}