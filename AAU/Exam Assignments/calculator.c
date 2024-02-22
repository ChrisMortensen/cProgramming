/*
	Navn			:	Christian Svalgaard Mortensen
	Email			:	csmo23@student.aau.dk
	Gruppe			:	1
	Studieretning	:	Cyber- og computer teknologi
*/

#include <stdio.h>
#include <math.h>

double run_calculator();					//	Run the calculator
void scan_data(char *, double *);			//	Scan operator and operand
int isOperatorBinary(char);					//	Check if operator is binary
void do_next_op(double *, char, double);	//	Perform the next operation

int main(void)
{
	double result = run_calculator();
	printf("Final result is: %.6lf", result);
	return 0;
}

double run_calculator()
{
	double accumulator = 0.0, operand = 0.0;
	char operator;
	do
	{
		scan_data(&operator, & operand);
		if (operator== 'q')
		{
			return accumulator;
		}
		do_next_op(&accumulator, operator, operand);
		printf("Result so far is %.6lf.\n", accumulator);
	} while (1);
}

void scan_data(char *operator, double * operand)
{
	printf("Enter operator: ");
	scanf(" %c", &*operator);
	if (isOperatorBinary(*operator))
	{
		printf("Enter operand: ");
		scanf(" %lf", &*operand);
	}
	else
	{
		*operand = 0.0;
	}
}

int isOperatorBinary(char operator)
{
	return (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^');
}

void do_next_op(double *accumulator, char operator, double operand)
{
	switch (operator)
	{
	case '+':
		*accumulator += operand;
		break;

	case '-':
		*accumulator -= operand;
		break;

	case '*':
		*accumulator *= operand;
		break;

	case '/':
		if (operand != 0.0)
		{
			*accumulator /= operand;
		}
		break;

	case '^':
		*accumulator = pow(*accumulator, operand);
		break;
		
	case '#':
		if (*accumulator >= 0.0)
		{
			*accumulator = sqrt(*accumulator);
		}
		break;

	case '%':
		*accumulator = -(*accumulator);
		break;

	case '!':
		if (*accumulator != 0.0)
		{
			*accumulator = 1.0 / *accumulator;
		}
		break;

	default:
		break;
	}
}