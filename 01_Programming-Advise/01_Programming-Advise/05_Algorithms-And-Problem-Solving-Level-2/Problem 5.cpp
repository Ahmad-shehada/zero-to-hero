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

void PrintDigits(int Number)
{
	int Remainder = 0;

	cout << "\nThe Digites is \n";

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = int(Number / 10);
		cout << Remainder << endl;
	}
}


int main()
{
	PrintDigits(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}