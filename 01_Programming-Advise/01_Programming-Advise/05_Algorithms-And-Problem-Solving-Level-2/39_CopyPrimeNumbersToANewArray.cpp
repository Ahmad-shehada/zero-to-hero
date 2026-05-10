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

void AddArrayElement(int arr[], int Element, int& arrLength)
{
	arr[arrLength] = Element;
	arrLength++;
}
void CopyOddNumberInArray(int arrSource[], int arrDestination[], int arrLength, int& arrLengthDestination)
{
	for (int i = 0; i < arrLength; i++)
		if (math::isPrime(arrSource[i]))
			AddArrayElement(arrDestination, arrSource[i], arrLengthDestination);
}

int main()
{
	int arr[100], arr_1[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");
	int arrLength_1 = 0;

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	CopyOddNumberInArray(arr, arr_1, arrLength, arrLength_1);

	cout << "\nThe length of arr_1 is " << arrLength_1 << endl;
	PrintArray(arr_1, arrLength_1);

	return 0;
}