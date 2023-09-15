#include <stdio.h>


void main(){
	//Show the output displayed by the following program lines when the data entered are 5 and 7
	
	int m,n; 
	
	printf("Enter two integers> ");
	scanf("%d%d", &m, &n);
	m = m + 5;
	n = 3 * n;
	
	printf("m = %d\nn = %d\n", m, n);

	return;
}