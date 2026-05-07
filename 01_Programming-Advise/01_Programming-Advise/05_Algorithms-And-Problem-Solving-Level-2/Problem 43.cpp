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

int EvenNumberCountInArray(int arr[100], int arrLength)
{
	int Counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 == 0)
			Counter++;
	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength = ReadPositiveNumber("Please enter a size of Array : ");

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	cout << "\nThe Count Of Even Number in Array is : " << EvenNumberCountInArray(arr, arrLength) << "\n";

	return 0;
}