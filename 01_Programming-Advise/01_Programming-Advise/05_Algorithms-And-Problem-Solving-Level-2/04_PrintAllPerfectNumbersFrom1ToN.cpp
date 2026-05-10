#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;

void PrintAllPerfectNumbersFrom1ToN(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		if (math::isPerfect(i))
			cout << i << " ";
	}

	cout << endl;
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintAllPerfectNumbersFrom1ToN(Number);

	return 0;
}