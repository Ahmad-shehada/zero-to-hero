#include <iostream>
#include <cmath>
#include "MyInput.h"
using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);
}
int MyFloor(float Number)
{
	int IntPart = int(Number);
	float FractionPart = abs(GetFractionPart(Number));

	if (Number >= 0)
		return IntPart;
	else
		return (FractionPart == 0) ? IntPart : --IntPart;
}

int main()
{
	float Number = in::ReadFloat("Please enter a Number : ");
	float NumberFloor = MyFloor(Number);

	cout << "The Number After Floor is " << NumberFloor << endl;
	cout << "The c++ Floor is " << floor(Number) << endl;

	return 0;
}