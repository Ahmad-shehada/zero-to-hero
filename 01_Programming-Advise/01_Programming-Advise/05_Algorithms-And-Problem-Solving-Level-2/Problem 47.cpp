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

int MyRound(float Number)
{
	int IntPart = int(Number);
	float FractionPart = abs(GetFractionPart(Number));

	if (FractionPart >= 0.5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
	{
		return IntPart;
	}

}

int main()
{
	float Number = ReadNumber("Please enter a Number : ");

	cout << "\nMy Round : " << MyRound(Number);
	cout << "\nRound C++ : " << round(Number) << "\n";

	return 0;
}