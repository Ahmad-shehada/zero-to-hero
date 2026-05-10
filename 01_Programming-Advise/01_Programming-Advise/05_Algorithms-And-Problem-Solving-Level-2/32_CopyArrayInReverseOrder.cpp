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
void CopyReverseArray(int arr[], int arrReverse[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arrReverse[i] = arr[arrLength - i - 1];
}

int main()
{
	int arr[100], arrReverse[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter arr Length : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	CopyReverseArray(arr, arrReverse, arrLength);
	PrintArray(arrReverse, arrLength);

	return 0;
}