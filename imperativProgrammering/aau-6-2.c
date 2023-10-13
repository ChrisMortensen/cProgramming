#include <stdio.h>

void time(int *, int *, int *);

void main(){
	int seconds = 0, minutes = 0, hours = 0;
	printf("Please provide the amount of seconds you want converted:\n");
	scanf(" %d", &seconds);
	time(&seconds, &minutes, &hours);
	printf("%d Hours, %d Minutes, %d Seconds", hours, minutes, seconds);
	return;
}

void time(int *seconds, int *minutes, int *hours){

	*minutes = *seconds / 60;
	*seconds %= 60;

	*hours = *minutes / 60;
	*minutes %= 60;
}