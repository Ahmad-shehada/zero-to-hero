#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}
int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumber(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << ' ';

	cout << endl;
}

void SumOfTwoArray(int arr_1[100], int arr_2[100], int arr_3[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr_3[i] = arr_1[i] + arr_2[i];
	}
}

int main()
{
	srand(time(NULL));

	int arrLength = ReadPositiveNumber("Enter Number of Element : ");
	int arr_1[100];
	int arr_2[100];
	int arr_3[100];

	FillArrayWithRandomNumber(arr_1, arrLength);
	FillArrayWithRandomNumber(arr_2, arrLength);

	cout << "\nArray 1 Element : ";
	PrintArray(arr_1, arrLength);

	cout << "\nArray 2 Element : ";
	PrintArray(arr_2, arrLength);

	SumOfTwoArray(arr_1, arr_2, arr_3, arrLength);

	cout << "\nArray 3 Element : ";
	PrintArray(arr_3, arrLength);

	return 0;
}