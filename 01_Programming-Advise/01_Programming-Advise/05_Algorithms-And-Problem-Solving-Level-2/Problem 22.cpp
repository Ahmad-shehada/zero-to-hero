#include <iostream>
#include <string>
using namespace std;


int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void ReadArray(int Array[100], int& ArrLength)
{
	ArrLength = ReadPositiveNumber("Please enter the length of Array : ");

	cout << "\nEnter Array Element : \n";
	for (int i = 0; i < ArrLength; i++)
		Array[i] = ReadPositiveNumber("Element [" + to_string(i + 1) + "] : ");
}
void PrintArray(int Array[100], int ArrLength)
{
	cout << "\nOriginal Array : ";
	
	for (int i = 0; i < ArrLength; i++)
		cout << Array[i] << ' ';

	cout << endl;
}

int TimeRepeat(int Array[100], int ArrLength, int DigitToCheck)
{
	int Counter = 0;

	for (int i = 0; i < ArrLength; i++)
	{
		if (Array[i] == DigitToCheck)
			Counter++;
	}

	return Counter;
}

int main()
{
	int Array[100], ArrLength, DigitToCheck;

	ReadArray(Array, ArrLength);

	DigitToCheck = ReadPositiveNumber("Please enter a Number Do you want to Check : ");

	PrintArray(Array, ArrLength);

	cout << DigitToCheck << " is repeated " << TimeRepeat(Array, ArrLength, DigitToCheck) << " Time(s)\n";

	return 0;
}