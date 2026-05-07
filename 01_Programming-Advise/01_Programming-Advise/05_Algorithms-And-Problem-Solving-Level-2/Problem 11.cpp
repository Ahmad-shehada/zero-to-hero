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

bool isPalindromeNumber(int Number)
{
	int ReversedNumber = 0;
	int Remainder = 0;
	int Temp = Number;


	while (Temp > 0)
	{
		Remainder = Temp % 10;
		Temp = int(Temp / 10);

		ReversedNumber = (ReversedNumber * 10) + Remainder;
		
	}

	return (Number == ReversedNumber);
}

void PrintResult(int Number)
{
	cout << endl;

	if (isPalindromeNumber(Number))
		cout << "Its Palindrome Number \n";
	else
		cout << "Its Not Palindorme Number \n";
}
 

int main()
{
	PrintResult(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}