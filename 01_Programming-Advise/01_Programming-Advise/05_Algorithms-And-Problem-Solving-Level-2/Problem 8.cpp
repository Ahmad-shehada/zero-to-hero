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

void PrintResult(short Digit,int Number)
{
	cout << "\nDigit " << Digit << " Frequency is " << CountDigitFrequency(Digit, Number) << " Time(s)." << endl;
}




int main()
{
	int Number = ReadPositiveNumber("Please enter a Number : ");
	short DigitToCheck = ReadPositiveNumber("Please enter a Digit : ");

	PrintResult(DigitToCheck, Number);

	return 0;
}