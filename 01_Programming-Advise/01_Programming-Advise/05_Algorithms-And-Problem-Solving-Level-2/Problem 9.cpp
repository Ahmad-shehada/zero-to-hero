#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int CountDigitFrequency(int DigitToCheck, int Number)
{
	int Remainder = 0;
	int FreqCount = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = int(Number / 10);

		if (DigitToCheck == Remainder)
			FreqCount++;
	}

	return FreqCount;
}

void PrintResult(int Number)
{
	cout << "\n";

	short FreqDigit = 0;

	for (int i = 0; i <= 9; i++)
	{
		FreqDigit = CountDigitFrequency(i, Number);
		
		if (FreqDigit > 0)
		{
			cout << "Digit " << i << " Frequency is " << FreqDigit << " Time(s).\n";
		}

	}
	
}


int main()
{
	PrintResult(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}