#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintNumberFromNTo1(int Number, bool State)
{
	if (State)
	{
		for (int i = 1; i <= Number; i++)
			cout << Number - i + 1 << endl;
	}
	else
	{
		for (int i = Number; i >= 1; i--)
			cout << i << endl;
	}
	
}

int main()
{
	int Number = in::ReadPositiveNumber("Please enter a Positive Number : ");
	PrintNumberFromNTo1(Number, 1);
	PrintNumberFromNTo1(Number, 0);

	return 0;
}