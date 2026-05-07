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

int SumOfDigits(int Number)
{
	int Sum = 0;
	int Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = int(Number / 10);
		Sum += Remainder;
	}

	return Sum;
}

void PrintResult(int Number)
{
	cout << "\nThe Sum of Digites is " << SumOfDigits(Number) << endl;
}


int main()
{
	PrintResult(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}