#include <iostream>
#include "MyInput.h"
#include "MyMath.h"

using namespace std;

void PrintEvenOrOdd(int Num)
{
	cout << "\n";

	if (math::isEven(Num))
		cout << "The Number is Even";
	else
		cout << "The Number is Odd";

	cout << "\n";
}

int main()
{
	int Num = in::ReadInt("Please enter a Number : ");
	PrintEvenOrOdd(Num);

	return 0;
}