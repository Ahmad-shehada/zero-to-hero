#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


int SumOfOddNumberFrom1ToN(int Number)
{
	int Sum = 0;

	for (int i = 1; i <= Number; i++)
	{
		if (!math::isEven(i))
			Sum += i;
	}

	return Sum;
}

int main()
{
	int Number = in::ReadPositiveNumber("Please enter a Positive Number : ");
	int Sum = SumOfOddNumberFrom1ToN(Number);
	cout << Sum << endl;

	return 0;
}