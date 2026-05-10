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


int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	return 0;
}