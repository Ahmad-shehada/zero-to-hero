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
void SumTwoArray(int arr[], int arr_1[],int arr_2[], int arrLength)
{
	for (int i = 0; i <= arrLength; i++)
		arr_2[i] = arr[i] + arr_1[i];
}

int main()
{
	int arr[100], arr_1[100], arr_2[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");
	int arrLength_1 = 0;

	FillArrayWithRandomNumber(arr, arrLength);
	FillArrayWithRandomNumber(arr_1, arrLength);

	PrintArray(arr, arrLength);
	PrintArray(arr_1, arrLength);

	SumTwoArray(arr, arr_1, arr_2, arrLength);
	
	PrintArray(arr_2, arrLength);

	return 0;
}