#include <iostream>
#include <string>
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
short CountEvenNumberInArray(int arr[], int arrLength)
{
	short Counter = 0;

	for (int i = 0; i < arrLength; i++)
		if (math::isEven(arr[i]))
			Counter++;

	return Counter;
}

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a size of arr : ");

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	cout << "Even Numbers Count is " << CountEvenNumberInArray(arr, arrLength);

	return 0;
}