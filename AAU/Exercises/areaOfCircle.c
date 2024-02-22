#include <stdio.h>
#define PI 3.14159

int main(void)
{
    double radius;

    printf("Please write the radius of the circle:\n");
    scanf("%lf", &radius);
    printf("The area of your circle is %lf.", PI*radius*radius);

    return 1;
}