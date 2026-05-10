#include <iostream>
#include "MyInput.h"
using namespace std;


void CountAllsDigitFrequency(short DigitsFreq[], int Number)
{
	int Digit = 0;

	while (Number > 0)
	{
		Digit = Number % 10;
		Number = int(Number / 10);
		DigitsFreq[Digit]++;
	}
}
void PrintDigitsFreq(short DigitFreq[])
{
	for (int i = 0; i <= 9; i++)
	{
		if (DigitFreq[i] != 0)
			cout << "The Number " << i << " repates " << DigitFreq[i] << " Times\n";
	}
}

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	short DigitsFreq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	CountAllsDigitFrequency(DigitsFreq, Number);
	PrintDigitsFreq(DigitsFreq);

	return 0;
}