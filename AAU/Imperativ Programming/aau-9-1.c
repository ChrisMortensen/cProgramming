#include <stdio.h>
#include <math.h>

void get_polynomium(double coeff[], int *degreep);
double eval_polynomium(const double coeff[], int degree, double x);

int main(void)
{
	int degree;
	double coefficients[9], x = 0;
	get_polynomium(coefficients, &degree);
	printf("x : ");
	scanf(" %lf", &x);
	double result = eval_polynomium(coefficients, degree, x);
	printf("P(%.2lf) : %.2lf", x, result);
	return 0;
}

void get_polynomium(double coeff[], int *degreep)
{
	printf("Degree : ");
	scanf(" %d", &*degreep);

	for (int i = 0; i <= *degreep; i++)
	{
		printf("Coefficient %d: ", i);
		scanf(" %lf", &coeff[i]);
	}
}

double eval_polynomium(const double coeff[], int degree, double x)
{
	double total = 0;
	for (int i = 0; i <= degree; i++)
	{
		total += coeff[i] * pow(x, i);
	}
	return total;
}