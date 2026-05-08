#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintNumberFrom1ToN(int Number)
{
	for (int i = 1; i <= Number; i++)
		cout << i << endl;
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Positive Number : ");
	PrintNumberFrom1ToN(Number);

	return 0;
}