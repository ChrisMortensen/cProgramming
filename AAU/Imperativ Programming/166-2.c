#include <stdio.h>

void main()
{

	int arrTime, speed, dist, depTime, arrH, arrM, travM, travH;

    printf("Enter arrival time, speed(km/h), and distance(km):\n");
    scanf("%d %d %d", &arrTime, &speed, &dist);

    arrH = arrTime / 100;
    arrM = arrTime % 100;

    travM = (60 * dist) / speed;
    travH = travM / 60;
    travM %= 60;

    depTime = (arrH - travH) * 100 + arrM - travM;

    printf("You need to depart by %04d.\n", depTime);

    return;
}