#include <iostream>
#include <cmath>
using namespace std;


int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

bool isPerfectNumber(int Number)
{
	int Limit = floor(sqrt(Number));
	int Sum = 1;
	int Temp = 0;

	for (int i = 2; i <= Limit; i++)
	{
		if (Number % i == 0)
		{
			Temp = Number / 2;

			if (Temp != i)
				Sum += Temp + i;
			else
				Sum += i;
		}
	}

	return Sum == Number;
}

void PrintResult(int Number)
{
	if (isPerfectNumber(Number))
		cout << "is Perfect Number\n";
	else
		cout << "Not Perfect Number";
}

int main()
{
	PrintResult(ReadPositiveNumber("Please enter a Number : "));


	return 0;
}