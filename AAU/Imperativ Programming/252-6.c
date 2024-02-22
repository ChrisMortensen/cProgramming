#include <stdio.h>
#include <stdbool.h>



void main(){
	char* onAxies = "n";
	int quadrant;
	float x, y;
	bool onAxiesY, onAxiesX;

	printf("Please provide the x and y cordinate for the point:");
	scanf("%f %f",&x,&y);

	onAxiesX = x==0 ? true : false;
	onAxiesY = y==0 ? true : false;

	onAxies = onAxiesX||onAxiesY ? "x" : "y";
	if (onAxiesX==true||onAxiesY==true)
	{
		printf("(%.1f, %.1f) is on the %s-axies", x, y, onAxies);

	} else
	{
		quadrant = x>0&&y>0 ? 1 : x>0&&y<0 ? 2 : x<0&&y<0 ? 3 : 4;
		printf("(%.1f, %.1f) is in quadrant %d.", x, y, quadrant);
	}
	
	return;
}