#include <iostream>
#include "MyInput.h"
using namespace std;

void PrintNumberPattern(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << i;

		cout << "\n";
	}

}


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	PrintNumberPattern(Number);

	return 0;
}