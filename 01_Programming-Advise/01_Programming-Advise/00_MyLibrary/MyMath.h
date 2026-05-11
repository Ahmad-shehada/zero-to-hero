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

	void Swap(int& FirstNumber, int& SecondNumber)
	{
		int Temp = FirstNumber;
		FirstNumber = SecondNumber;
		SecondNumber = Temp;
	}

	unsigned long long Factorial(short Number)
	{
		unsigned long long Factorial = 1;

		for (int i = 2; i <= Number; i++)
			Factorial *= i;

		return Factorial;
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

	bool isPerfect(int Number)
	{
		int Limit = Number / 2;
		int Sum = 1;

		for (int i = 2; i <= Limit; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}

		return (Sum == Number && Number != 1);
	}

	int ReverseNumber(int Number)
	{
		int Digit = 0;
		int ReverseNumber = 0;

		while (Number != 0)
		{
			Digit = Number % 10;
			Number /= 10;
			ReverseNumber = (ReverseNumber * 10) + Digit;
		}

		return ReverseNumber;
	}

	bool isPalindrome(int Number)
	{
		return Number == ReverseNumber(Number);
	}
}