#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintDigitsInAReversedOrder(int Number)
{
	int Digit = 0;

	while(Number != 0)
	{
		Digit = Number % 10;
		Number /= 10;
		cout << Digit << endl;
	}
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintDigitsInAReversedOrder(Number);

	return 0;
}