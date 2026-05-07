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

void PrintNumberPattern(int Number)
{
	cout << endl << "The Number Pattern is : \n";

	for (int i = 1; i <= Number; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << i << " ";

		cout << endl;
	}
}

int main()
{
	PrintNumberPattern(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}