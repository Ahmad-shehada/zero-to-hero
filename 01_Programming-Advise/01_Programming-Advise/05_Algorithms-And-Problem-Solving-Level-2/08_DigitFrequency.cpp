#include <iostream>
#include "MyInput.h"
using namespace std;

int DigitFrequency(int DigitToCheck, int Number)
{
	int Digit = 0;
	int Counter = 0;

	while (Number != 0)
	{
		Digit = Number % 10;
		Number /= 10;
		
		if (DigitToCheck == Digit)
			Counter++;
	}

	return Counter;
}


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	int DigitToCheck = in::ReadIntNumberInRange(0, 9, "Please enter a Digit to check : ");
	int DigitFreq = DigitFrequency(DigitToCheck, Number);

	cout << DigitFreq << endl;

	return 0;
}