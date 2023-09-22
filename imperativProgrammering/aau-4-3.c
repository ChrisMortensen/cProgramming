#include <stdio.h>

void main(){

	int n, c, result = 0;
	printf("Provide a whole number:\n");
	scanf("%d", &n);

	/* 
	//FOR LOOPS
	if (n > 0){
		for (int i = n; i < n * 2; i++){
			result += i;
		}
	} else {
		for (int i = n; i > n * 2; i--){
			result += i;
		}
	}
	*/
	/* 
	//WHILE LOOPS
	c=n;
	if (n > 0){
		while (c < n * 2)
		{
			result += c;
			c++;
		}
	} else {
		while (c > n * 2)
		{
			result += c;
			c--;
		}
	}
	*/
	
	printf("The result is %d.\n", result);

	return;
}