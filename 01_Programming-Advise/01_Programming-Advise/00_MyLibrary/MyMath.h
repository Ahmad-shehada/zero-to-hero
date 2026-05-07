#pragma once

#include <iostream>
#include <cmath>
using namespace std;


namespace math
{
	const double PI = 3.141592654;

	bool isEven(int Number)
	{
		return (Number & 1) == 0;
	}

	unsigned long long Factorial(short Number)
	{
		unsigned long long Factorial = 1;

		for (int i = 2; i <= Number; i++)
			Factorial *= i;

		return Factorial;
	}
}