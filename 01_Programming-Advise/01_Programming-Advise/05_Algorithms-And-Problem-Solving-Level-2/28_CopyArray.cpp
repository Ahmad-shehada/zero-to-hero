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
void CopyArray(int arrSource[], int arrDestination[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arrDestination[i] = arrSource[i];
}

int main()
{
	int arr[100], arr_1[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	CopyArray(arr, arr_1, arrLength);

	PrintArray(arr_1, arrLength);

	return 0;
}