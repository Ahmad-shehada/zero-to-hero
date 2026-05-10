#include <iostream>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;

void FillArrayWithRandomNumber(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = random::RandomNumber(1, 100);
}
void PrintArray(int arr[], int arrLength)
{
	cout << "Original array : ";

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}

void AddArrayElement(int arr[], int Element, int& arrLength)
{
	arr[arrLength] = Element;
	arrLength++;
}
void CopyArray(int arrSource[], int arrDestination[], int arrLength, int& arrLength_1)
{
	for (int i = 0; i < arrLength; i++)
		AddArrayElement(arrDestination, arrSource[i], arrLength_1);
}

int main()
{
	int arr[100], arr_1[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");
	int arrLength_1 = 0;

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	CopyArray(arr, arr_1, arrLength, arrLength_1);

	cout << "\nThe length of arr_1 is " << arrLength_1 << endl;
	PrintArray(arr_1, arrLength_1);

	return 0;
}