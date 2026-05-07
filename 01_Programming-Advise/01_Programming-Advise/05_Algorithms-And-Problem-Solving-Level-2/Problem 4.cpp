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

bool isPerfectNumber(int Number)
{
	int Limit = ceil(Number / 2.0);
	int Sum = 0;

	for (int Counter = 1; Counter <= Limit; Counter++)
	{
		if (Number % Counter == 0 && Number != 1)
			Sum += Counter;
	}

	return (Sum == Number);
}

void PrintPerfectNumberFrom1ToN(int Number)
{
	cout << "\nThe Perfect Number From 1 To " << Number << "\n";

	for (int i = 1; i <= Number; i++)
	{
		if (isPerfectNumber(i))
			cout << i << endl;
	}
}


int main()
{
	PrintPerfectNumberFrom1ToN(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}