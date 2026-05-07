#include <iostream>
#include <cmath>
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

int GetReversedNumber(int Number)
{
	int ReversedNumber = 0;
	int Remainder = 0;
	

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = int(Number / 10);

		ReversedNumber = (ReversedNumber * 10) + Remainder;
	}

	return ReversedNumber;
}

void PrintResult(int Number)
{
	cout << "\nThe Reversed of Number is " << GetReversedNumber(Number) << endl;
}


int main()
{
	PrintResult(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}