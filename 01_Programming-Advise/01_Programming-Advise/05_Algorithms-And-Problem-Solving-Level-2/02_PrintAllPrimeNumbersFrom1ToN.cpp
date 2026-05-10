#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;

void PrintAllPrimeNumbersFrom1ToN(int Num)
{
	for (int i = 1; i <= Num; i++)
	{
		if (math::isPrime(i))
			cout << i << endl;
	}
}

int main()
{
	int Num = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintAllPrimeNumbersFrom1ToN(Num);

	return 0;
}
