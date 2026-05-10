#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;

void PrintDigitsInOrder(int Number)
{
	int Digit = 0;

	while (Number != 0)
	{
		Digit = Number % 10;
		Number /= 10;
		cout << Digit << endl;
	}
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	int ReverseNumber = math::ReverseNumber(Number);
	PrintDigitsInOrder(ReverseNumber);

	return 0;
}