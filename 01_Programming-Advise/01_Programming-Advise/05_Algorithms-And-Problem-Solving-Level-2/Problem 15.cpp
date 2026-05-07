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

void PrintLetterPattern(int Number)
{
	cout << endl << "The Letter Pattern is : \n";

	for (int i = 65; i <= 65 + Number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
			cout << char(i) << " ";

		cout << endl;
	}
}

int main()
{
	PrintLetterPattern(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}