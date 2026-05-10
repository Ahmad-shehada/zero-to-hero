#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintInvertedNumberPattern(int Number)
{
	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
			cout << i;

		cout << endl;
	}
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintInvertedNumberPattern(Number);

	return 0;
}