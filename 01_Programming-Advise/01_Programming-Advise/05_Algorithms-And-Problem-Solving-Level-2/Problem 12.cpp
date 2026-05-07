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

void PrintInvertedNumberPattern(int Number)
{
	cout << endl << "The Inverted Number Pattern is : \n";

	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
			cout << i << " ";

		cout << endl;
	}
}

int main()
{
	PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}