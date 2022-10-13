#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned short nextToBeDevided;
unsigned short myIndex = 0;
unsigned short divisionResult = 0;
unsigned short lastDigit;
unsigned short myRemainder;


int calculatingPowerBecauseICantImportMathH(int base, int power)
{
	int res = base;
	if (power == 0)
	{
		res = 1;
	}
	else
	{
		for (int p = 1; p < power; p++)
		{
			res = res * base;
		}

	}
	return res;
}

void divider()
{
	myRemainder = nextToBeDevided % lastDigit;
	nextToBeDevided = nextToBeDevided / lastDigit;

	divisionResult = divisionResult + (myRemainder * calculatingPowerBecauseICantImportMathH(10, myIndex));
	myIndex++;
	if (nextToBeDevided == 0) {
		return;
	}
	//We can remove this if loop but then its gonna spam you until the code breaks
	divider();
}
int invalidNumber()
{
	printf("Invalid number");
	exit(0);
}


int main()
{
	unsigned short number;
	printf("Enter a number: ");
	scanf("%hu", &number);
	lastDigit = number % 10;
	nextToBeDevided = number / 10;
	(nextToBeDevided / 10 < 10) ? printf("Calculating... \n") : invalidNumber();
	lastDigit == 3 || lastDigit == 4 || lastDigit == 5 ? divider() : invalidNumber();
	printf("Your number is %hu", divisionResult);
	return 0;
}
