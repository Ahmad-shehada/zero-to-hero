#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintLetterPattern(int Number)
{
	for (int i = 65; i <= 65 + Number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
			cout << char(i);

		cout << endl;
	}
}


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintLetterPattern(Number);

	return 0;
}