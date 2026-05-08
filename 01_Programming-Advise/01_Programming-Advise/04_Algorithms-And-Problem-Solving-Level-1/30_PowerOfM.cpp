#include <iostream>
#include "MyInput.h"
using namespace std;

int Pow(int Base, int Power)
{
	int Result = Base;

	for (int i = 2; i <= Power; i++)
		Result *= Base;

	return Result;
}


int main()
{
	int Base = in::ReadInt("Please enter a Base : ");
	int Power = in::ReadInt("Please enter a power : ");
	int Result = Pow(Base, Power);
	
	cout << Result << endl;
}