#include <iostream>
#include <cstdlib>
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

void fillArrayWithRandomNumber(int arr[100], int arrLength)
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

int MaxNumberInArray(int arr[100], int arrLength)
{
	int Max = arr[0];

	for (int i = 0; i < arrLength; i++)
		if (Max < arr[i])
			Max = arr[i];

	return Max;
}

int main()
{
	srand(time(NULL));

	int arrLength = ReadPositiveNumber("Enter Number of Element : ");
	int arr[100];

	fillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Element : ";
	PrintArray(arr, arrLength);

	cout << "\nMax Number : " << MaxNumberInArray(arr, arrLength) << "\n";

	return 0;
}