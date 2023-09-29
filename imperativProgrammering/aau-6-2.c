#include <stdio.h> //Not done


typedef struct Time {
	int seconds; 
	int minutes; 
	int hours;

} Time;

Time hours_minutes_seconds(int seconds);

void main(){
	int seconds, minutes, hours;
	printf("Please provide the amount of seconds you want converted:\n");
	scanf(" %d", &seconds);
	Time time = hours_minutes_seconds(seconds);
	printf("%d Hours, %d Minutes, %d Seconds", time.hours, time.minutes, time.seconds);
	return;
}

Time hours_minutes_seconds(int seconds){
	Time result;

	int minutes, hours;
	minutes = seconds / 60;
	seconds %= 60;

	hours = minutes / 60;
	minutes %= 60;

	result.seconds = seconds;
	result.minutes = minutes;
	result.hours = hours;
	
	return result;
}