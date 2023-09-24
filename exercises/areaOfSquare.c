#include <stdio.h>

int main(void)
{
    double side, area;

    scanf("%lf", &side);
    area=side*side;

    printf("The area of a square whose side length is %lf cm is %lf square cm.", side, area);

    /*
    printf("Skriv 3 tal:\n");
    scanf("%d %d %d", &a,&b,&c);
    printf("a: %d, b: %d, c: %d",a,b,c);
    */
    return 1;
}