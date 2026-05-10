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
bool isPalindromArray(int arr[], int arrLength)
{
	int Limit = arrLength / 2;

	for (int i = 0; i < Limit; i++)
		if (arr[i] != arr[arrLength - i - 1])
			return false;

	return true;
}

int main()
{
	int arr[100];
	int arrLength = 0;

	InputUserNumberInArray(arr, arrLength);

	cout << "\nThe size of array is " << arrLength << endl;
	PrintArray(arr, arrLength);

	if (isPalindromArray(arr, arrLength))
		cout << "Its a Palindrom Array" << endl;
	else
		cout << "Its not a Palindrom Array" << endl;

	return 0;
}