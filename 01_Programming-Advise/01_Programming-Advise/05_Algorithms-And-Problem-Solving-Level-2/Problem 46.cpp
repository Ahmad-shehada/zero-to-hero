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

float MyABS(float Number)
{
	if (Number >= 0)
		return (Number);
	else
		return (Number * -1);
}



int main()
{
	float Number = ReadNumber("Please enter a Number : ");

	cout << "\nMy ABS : " << MyABS(Number);
	cout << "\nABS C++ : " << abs(Number) << "\n";

	return 0;
}