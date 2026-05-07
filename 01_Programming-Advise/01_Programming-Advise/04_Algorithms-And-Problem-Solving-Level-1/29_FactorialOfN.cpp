#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


int main()
{
	short Number = in::ReadPositiveNumber("Please enter a Positive Number : ");
	unsigned long long Factorial = math::Factorial(Number);

	cout << Factorial << endl;
}