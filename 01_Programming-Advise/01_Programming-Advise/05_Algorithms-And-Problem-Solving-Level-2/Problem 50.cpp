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

float MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = ReadNumber("Please enter a Number : ");

	cout << "\nMy Sqrt : " << MySqrt(Number);
	cout << "\nSqrt C++ : " << sqrt(Number) << "\n";

	return 0;
}