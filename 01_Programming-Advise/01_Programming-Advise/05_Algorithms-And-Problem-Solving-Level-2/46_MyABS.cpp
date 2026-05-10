#include <iostream>
#include <cmath>
#include "MyInput.h"
using namespace std;


int MyABS(float Number)
{
	return (Number >= 0) ? Number : Number * -1;
}


int main()
{
	float Number = in::ReadFloat("Please enter a Number : ");
	float NumberABS = MyABS(Number);

	cout << "The Number After ABS is " << NumberABS << endl;
	cout << "The c++ ABS is " << abs(Number) << endl;

	return 0;
}