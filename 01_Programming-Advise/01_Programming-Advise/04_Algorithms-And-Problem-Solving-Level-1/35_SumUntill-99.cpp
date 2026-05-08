#include <iostream>
#include <cstring>
#include "MyInput.h"
using namespace std;

int SumUntilN(const int STOP_NUMBER)
{
	int Sum = 0;
	int Number = 0;
	int Counter = 1;

	do
	{
		Sum += Number;
		Number = in::ReadInt("Please enter a Number_" + to_string(Counter) + " : ");
		Counter++;

	} while (STOP_NUMBER != Number);

	return Sum;
}

int main()
{
	int Sum = SumUntilN(-99);
	cout << Sum << endl;

	return 0;
}