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

int MyFloor(float Number)
{
	int IntPart = int(Number);
	float FractionPart = abs(GetFractionPart(Number));

	if (FractionPart > 0)
	{
		if (Number >= 0)
			return IntPart;
		else
			return IntPart - 1;
	}
	else
	{
		return IntPart;
	}
}

int main()
{
	float Number = ReadNumber("Please enter a Number : ");

	cout << "\nMy Floor : " << MyFloor(Number);
	cout << "\nFloor C++ : " << floor(Number) << "\n";

	return 0;
}