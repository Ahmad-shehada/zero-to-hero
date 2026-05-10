#include <iostream>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;


void FillArray(int arr[100], int& arrLength)
{
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 10;
	arr[4] = 10;
	arr[5] = 10;
	arr[6] = 10;
	arr[7] = 20;
	arr[8] = 30;
	arr[9] = 10;

	arrLength = 10;
}
void PrintArray(int arr[], int arrLength)
{
	cout << "Original array : ";

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}

short FindIndex(int arr[100], int arrLength, int NumberToSearch)
{
	for (int i = 0; i < arrLength; i++)
		if (arr[i] == NumberToSearch)
			return i;

	return -1;
}
bool isNumberInArray(int arr[100], int arrLength, int NumberToSearch)
{
	return FindIndex(arr, arrLength, NumberToSearch) != -1;
}

void AddArrayElement(int arr[], int Element, int& arrLength)
{
	arr[arrLength] = Element;
	arrLength++;
}
void CopyDistinctNumberInArray(int arrSource[], int arrDestination[], int arrLength, int& arrLengthDestination)
{
	for (int i = 0; i < arrLength; i++)
		if (!isNumberInArray(arrDestination, arrLengthDestination, arrSource[i]))
			AddArrayElement(arrDestination, arrSource[i], arrLengthDestination);
}

int main()
{
	int arr[100], arr_1[100];
	int arrLength = 0;
	int arrLength_1 = 0;

	FillArray(arr, arrLength);
	PrintArray(arr, arrLength);

	CopyDistinctNumberInArray(arr, arr_1, arrLength, arrLength_1);
	PrintArray(arr_1, arrLength_1);

	return 0;
}