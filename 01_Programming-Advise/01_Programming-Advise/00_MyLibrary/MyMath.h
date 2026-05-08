#pragma once

#include <iostream>
#include <cmath>
using namespace std;


namespace math
{
	enum enOperator { Add = '+', Sub = '-', Mult = '*', Div = '/' };

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

	double SimpleCalculate(double FirstNumber, double SecondNumber, enOperator Operator)
	{
		switch (Operator)
		{
		case enOperator::Add:
			return (FirstNumber + SecondNumber);
		case enOperator::Sub:
			return (FirstNumber - SecondNumber);
		case enOperator::Mult:
			return (FirstNumber * SecondNumber);
		case enOperator::Div:
			return (FirstNumber / SecondNumber);
		default:
			return -1;
		}

	}
	
	bool isPrime(int Number)
	{
		int Limit = Number / 2;
		
		if (Number == 1)
			return false;

		for (int i = 2; i <= Limit; i++)
		{
			if (Number % i == 0)
				return false;
		}

		return true;
	}
}