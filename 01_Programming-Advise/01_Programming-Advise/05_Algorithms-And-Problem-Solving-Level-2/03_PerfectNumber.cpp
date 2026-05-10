#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enetr a Number : ");
	
	if (math::isPerfect(Number))
		cout << "Its Perfect\n";
	else
		cout << "Its not Perfect\n";

	return 0;
}