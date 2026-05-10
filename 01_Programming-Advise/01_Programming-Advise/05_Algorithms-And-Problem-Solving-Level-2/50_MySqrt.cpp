#include <iostream>
#include <cmath>
#include "MyInput.h"
using namespace std;

float MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = in::ReadFloat("Please enter a Number : ");
	float NumberSqrt = MySqrt(Number);
	
	cout << "The Number After Sqrt is " << NumberSqrt << endl;
	cout << "The c++ Floor is " << sqrt(Number) << endl;

	return 0;
}