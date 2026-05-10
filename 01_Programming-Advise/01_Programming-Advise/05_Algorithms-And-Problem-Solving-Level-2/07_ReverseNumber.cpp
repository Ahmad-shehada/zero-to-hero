#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	int ReverseNumber = math::ReverseNumber(Number);

	cout << ReverseNumber << endl;

	return 0;
}