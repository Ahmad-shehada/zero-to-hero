#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string Message)
{
	float Number;

	cout << Message;
	cin >> Number;

	return Number;
}

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyCeil(float Number)
{
	int IntPart = int(Number);
	float FractionPart = GetFractionPart(Number);

	if (FractionPart > 0)
	{
		if (Number >= 0)
			return IntPart + 1;
		else
			return IntPart;
	}
	else
	{
		return IntPart;
	}
}

int main()
{
	float Number = ReadNumber("Please enter a Number : ");

	cout << "\nMy Ceil : " << MyCeil(Number);
	cout << "\nCeil C++ : " << ceil(Number) << "\n";

	return 0;
}