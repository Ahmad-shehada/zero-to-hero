#include <iostream>
#include <string>
#include "MyInput.h"
using namespace std;

void AddArrayElement(int arr[], int Element, int& arrLength)
{
	arr[arrLength] = Element;
	arrLength++;
}
void InputUserNumberInArray(int arr[], int& arrLength)
{
	bool AddMore = false;
	int Element = 0;

	do
	{
		Element = in::ReadInt("Element [" + to_string(arrLength + 1) + "] : ");
		AddArrayElement(arr, Element, arrLength);

		AddMore = in::ReadBoolean("Do you want to add more number [1]Yes, [0]No : ");

	} while (AddMore);
}
void PrintArray(int arr[], int arrLength)
{
	cout << "Original array : ";

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}


int main()
{
	int arr[100];
	int arrLength = 0;

	InputUserNumberInArray(arr, arrLength);

	cout << "\nThe size of array is " << arrLength << endl;
	PrintArray(arr, arrLength);

	return 0;
}