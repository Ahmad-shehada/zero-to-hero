#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
#include "MyRandom.h"
using namespace std;

void FillArray1ToN(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = i + 1;
}
void PrintArray(int arr[], int arrLength)
{
	cout << "Original array : ";

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}
void ShuffleArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		math::Swap(arr[random::RandomNumber(0, arrLength - 1)], arr[random::RandomNumber(0, arrLength - 1)]);
}

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Number : ");
	
	FillArray1ToN(arr, arrLength);
	PrintArray(arr, arrLength);

	ShuffleArray(arr, arrLength);
	PrintArray(arr, arrLength);

	return 0;
}