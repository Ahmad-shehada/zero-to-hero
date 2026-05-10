#include <iostream>
#include <string>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;

void ReadArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = in::ReadInt("Element [" + to_string(i + 1) + "] : ");
}
void PrintArray(int arr[], int arrLength)
{
	cout << "Original array : ";

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}
short NumberCount(int arr[], int arrLength, int NumberToCheck)
{
	short Counter = 0;

	for (int i = 0; i < arrLength; i++)
		if (NumberToCheck == arr[i])
			Counter++;

	return Counter;
}

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");
	int NumberToCheck = 0;

	ReadArray(arr, arrLength);

	NumberToCheck = in::ReadInt("Please enter a Number To Check : ");

	PrintArray(arr, arrLength);
	cout << NumberToCheck << " is repeated " << NumberCount(arr, arrLength, NumberToCheck) << " Time(s)\n";

	return 0;
}