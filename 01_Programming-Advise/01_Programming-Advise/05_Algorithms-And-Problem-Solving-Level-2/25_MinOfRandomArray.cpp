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
int MinNumberInArray(int arr[], int arrLength)
{
	int Min = arr[0];

	for (int i = 1; i < arrLength; i++)
		if (arr[i] < Min)
			Min = arr[i];

	return Min;
}

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	cout << "The min Number is " << MinNumberInArray(arr, arrLength) << endl;

	return 0;
}