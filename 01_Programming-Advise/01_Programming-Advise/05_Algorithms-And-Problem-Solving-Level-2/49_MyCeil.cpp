#include <iostream>
#include <cmath>
#include "MyInput.h"
using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);
}
int MyCeil(float Number)
{
	int IntPart = int(Number);
	float FractionPart = abs(GetFractionPart(Number));

	if (Number >= 0)
		return (FractionPart == 0) ? IntPart : ++IntPart;
	else
		return  IntPart;
}

int main()
{
	float Number = in::ReadFloat("Please enter a Number : ");
	float NumberCeil = MyCeil(Number);

	cout << "The Number After Floor is " << NumberCeil << endl;
	cout << "The c++ Floor is " << ceil(Number) << endl;

	return 0;
}