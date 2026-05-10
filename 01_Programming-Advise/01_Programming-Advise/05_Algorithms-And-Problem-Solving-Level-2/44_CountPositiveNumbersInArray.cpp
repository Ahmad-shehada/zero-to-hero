#include <iostream>
#include <string>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;

void FillArrayWithRandomNumber(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = random::RandomNumber(-100, 100);
}
void PrintArray(int arr[], int arrLength)
{
	cout << "Original array : ";

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}
short CountPositiveNumberInArray(int arr[], int arrLength)
{
	short Counter = 0;

	for (int i = 0; i < arrLength; i++)
		if (arr[i] >= 0)
			Counter++;

	return Counter;
}

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a size of arr : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	cout << "Even Numbers Count is " << CountPositiveNumberInArray(arr, arrLength);

	return 0;
}