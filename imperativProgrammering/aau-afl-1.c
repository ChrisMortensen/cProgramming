#include <stdio.h>

void main(){

	int weeks, days, hours, minutes, seconds;

	printf("Please input an amount of time in seconds:\n");
	scanf("%d", &seconds);

	//First way
	minutes = seconds / 60;
	seconds %= 60;

	hours = minutes / 60;
	minutes %= 60;

	days = hours / 24;
	hours %= 24;

	weeks = days / 7;
	days %= 7;


	/* 
	//Second Way
	weeks = seconds / (7 * 24 * 60 * 60);
	seconds %= (7 * 24 * 60 * 60);

	days = seconds / (24 * 60 * 60);
	seconds %= (24 * 60 * 60);

	hours = seconds / (60 * 60);
	seconds %= (60 * 60);

	minutes = seconds / 60;
	seconds %= 60;
	*/
	

	printf("%d Weeks, %d Days, %d Hours, %d Minutes, %d Seconds", weeks, days, hours, minutes, seconds);
}