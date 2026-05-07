#include <iostream>
#include "MyInput.h"
using namespace std;


float CalculateHalfNumber(float Number)
{
	return Number / 2.0;
}


int main()
{
	float Number = in::ReadFloat("Please enter a Number : ");
	float HalfNumber = CalculateHalfNumber(Number);
	cout << HalfNumber << endl;
}