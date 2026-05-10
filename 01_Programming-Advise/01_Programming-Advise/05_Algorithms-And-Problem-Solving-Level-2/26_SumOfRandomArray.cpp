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
int SumArray(int arr[], int arrLength)
{
	int Sum = 0;

	for (int i = 0; i < arrLength; i++)
			Sum += arr[i];

	return Sum;
}

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	cout << "The Sum Number is " << SumArray(arr, arrLength) << endl;

	return 0;
}