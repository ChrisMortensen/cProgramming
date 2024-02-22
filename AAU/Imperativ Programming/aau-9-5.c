#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 100
#define MAXVALUE 60

void createArray(double *);
void printArray(double *);
void sortArray(double *);
int compare(const void *, const void *);

int main(void){

	double *array;

	array = (double*)malloc(ARRAYSIZE * sizeof(double));
	createArray(array);
    sortArray(array);
	printArray(array);

	free(array);
	return 0;
}

void createArray(double array[])
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        array[i] = rand() % (MAXVALUE * 100) / 100.0;
    }
}

void printArray(double array[])
{
    printf("Array: \n");
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        printf("%2d : %2.2lf\n", i, array[i]);
    }
}

void sortArray(double *array){
    qsort(array, ARRAYSIZE, sizeof(double), compare);
}


int compare(const void *a, const void *b){
    double *c = (double*)a,
    *d = (double*)b;
    if(*c > *d){
        return 1;
    } else if (*c < *d){
        return -1;
    } else {
        return 0;
    }
}