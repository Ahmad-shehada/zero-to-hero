#include <iostream>
using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

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
 
enPrimeOrNot CheckPrime(int Number)
{
	int Limit = ceil(Number / 2.0);

	for (int Counter = 2; Counter <= Limit; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}

	return enPrimeOrNot::Prime;
}

void PrintPrimeNumbersFrom1ToN(int Number)
{
	cout << "\nPrime Numbers From 1 To " << Number << " are :\n";

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeOrNot::Prime)
			cout << i << endl;
	}
}

int main()
{
	PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}
