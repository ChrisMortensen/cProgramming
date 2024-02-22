#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAYSIZE 20
#define MAXVALUE 60

void createArray(int array[]);
void printArray(int array[]);
int findMax(int array[]);
int findMin(int array[]);

int main(void)
{
    srand(time(NULL));

    int array[ARRAYSIZE];
    createArray(array);
    printArray(array);

    return 0;
}

void createArray(int array[])
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        array[i] = rand() % MAXVALUE;
    }
}

void printArray(int array[])
{
    printf("Array: \n");
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        printf("[%d] : %i\n", i, array[i]);
    }
    printf("Max : %d\n", findMax(array));
    printf("Min : %d\n", findMin(array));
}

int findMax(int array[])
{
    int biggest = array[0];
    for (int i = 1; i < ARRAYSIZE; i++)
    {
        if(array[i] > biggest){
            biggest = array[i];
        }
    }
    return biggest;
}

int findMin(int array[])
{
    int smallest = array[0];
    for (int i = 1; i < ARRAYSIZE; i++)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
        }
    }
    return smallest;
}