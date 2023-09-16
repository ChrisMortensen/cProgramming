#include <stdio.h>
int main()
{
    int seconds=0,minutes=0,hours=0,days=0,weeks=0;
    int calculation_for_minutes=0,calculation_for_hours=0;
    int calculation_for_days=0,calculation_for_weeks=0;
    int number=0;

    printf("Test:");
    scanf("%d", &number);
    
	seconds=number;

	calculation_for_minutes=seconds/60;
    seconds%=60;

    calculation_for_hours=calculation_for_minutes/60;
    calculation_for_minutes%=60;
    
	calculation_for_days=calculation_for_hours/24;
    calculation_for_hours%=24;
    
	calculation_for_weeks=calculation_for_days/7;
    calculation_for_days%=7;
    
	minutes=calculation_for_minutes;
	hours=calculation_for_hours;
	days=calculation_for_days;
	weeks=calculation_for_weeks;

	printf(" Seconds: %d\n Minutes: %d\n Hours: %d\n Days: %d\n Weeks: %d",seconds,minutes,hours,days,weeks);
    
	return 0;

}