#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *createArray(int);
void printArray(int *, int);

int main(void)
{
    srand(time(NULL));

	int n;
	printf("ArraySize : ");
	scanf(" %d", &n);

    int *array = createArray(n);
    printArray(array, n);

	free(array);
    return 0;
}

int *createArray(int arraySize)
{
	int *array;
	array = (int *)malloc(arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 6 + 1;
    }
	return array;
}

void printArray(int *array, int arraySize)
{
    printf("Array\n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%2d : %i\n", i, array[i]);
    }
}   