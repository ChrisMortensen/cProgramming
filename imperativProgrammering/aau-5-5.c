#include <stdio.h>


int isLeapYearNew(int);
int isLeapYearOld(int);


int main(void){
	/*
	int year;
	printf("Please provide a year:\n");
	printf("Year : ");
	scanf(" %d", &year);
	printf("%d", isLeapYear(year));
	*/
	for (int i = 1901; i < 2100; i++)
	{
		if (isLeapYearNew(i)!=isLeapYearOld(i))
		{
			printf("Problem in year %d.\n", i);
		}
	}
	printf("Complete.\n");
	
	return 0;
}

int isLeapYearNew(int year){
//	return year = year%400==0 ? 1 : year%100==0 ? 0 : year%4==0 ? 1 : 0;
	return year%4==0 && !year%100==0 || year%400==0;

}

int isLeapYearOld(int year){
  int res;
  if (year % 400 == 0)
    res = 1;
  else if (year % 100 == 0)
    res = 0;
  else if (year % 4 == 0)
    res = 1;
  else res = 0;
  return res;
}
