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

void PrintInvertedLetterPattern(int Number)
{
	cout << endl << "The Inverted Letter Pattern is : \n";

	for (int i = 65 + Number - 1 ; i >= 65; i--)
	{
		for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
			cout << char(i) << " ";

		cout << endl;
	}
}

int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}