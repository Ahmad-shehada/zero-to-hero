#include <iostream>
#include "MyInput.h"
using namespace std;

int SumOfDigits(int Number)
{
	int Digit = 0;
	int Sum = 0;

	while (Number != 0)
	{
		Digit = Number % 10;
		Number /= 10;
		Sum += Digit;
	}
	return Sum;
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	int Sum = SumOfDigits(Number);

	cout << Sum << endl;

	return 0;
}