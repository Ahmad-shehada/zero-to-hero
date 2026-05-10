#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintInvertedLetterPattern(int Number)
{
	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
			cout << char(i);

		cout << endl;
	}
}


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintInvertedLetterPattern(Number);

	return 0;
}