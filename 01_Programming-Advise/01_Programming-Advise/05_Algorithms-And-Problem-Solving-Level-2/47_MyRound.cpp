#include <iostream>
#include <cmath>
#include "MyInput.h"
using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyRound(float Number)
{
	int IntPart = int(Number);
	float FractionPart = abs(GetFractionPart(Number));

	if (FractionPart >= 0.5)
		return (IntPart >= 0) ? ++IntPart : --IntPart;
	else
		return IntPart;
}


int main()
{
	float Number = in::ReadFloat("Please enter a Number : ");
	float NumberRound = MyRound(Number);

	cout << "The Number After Round is " << NumberRound << endl;
	cout << "The c++ Round is " << round(Number) << endl;

	return 0;
}