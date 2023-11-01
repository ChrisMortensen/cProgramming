#include <stdio.h>
#include <math.h>

typedef enum {
	hit,
	stand,
	doubleDown,
	dealerTurn
} Action;

void main()
{
	Action act = hit;

	switch (act)
	{
	case hit:
		printf("%d\n", act);
		act++;
		break;
	case stand:
		printf("%d\n", act);
		act=dealerTurn;
		break;
	case doubleDown:
		printf("%d\n", act);
		break;
	case dealerTurn:
		printf("%d\n", act);
		break;
	default:
		break;
	}
	return;
}