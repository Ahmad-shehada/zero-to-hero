#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
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
void CopyArrayOnlyPrimeNumber(int arrSource[], int arrDestination[], int arrLength, int& arrLength_1)
{
	int Counter = 0;

	for (int i = 0; i < arrLength; i++)
		if (math::isPrime(arrSource[i]))
		{
			arrDestination[Counter] = arrSource[i];
			Counter++;
		}

	arrLength_1 = Counter;
}

int main()
{
	int arr[100], arr_1[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");
	int arrLength_1 = 0;

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	CopyArrayOnlyPrimeNumber(arr, arr_1, arrLength, arrLength_1);

	PrintArray(arr_1, arrLength_1);

	return 0;
}