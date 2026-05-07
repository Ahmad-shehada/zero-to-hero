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

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[arrLength - i - 1];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arrLength = ReadPositiveNumber("Please enter the size of Array : ");
	int arr[100];
	int arrReversed[100];

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray 1 : ";
	PrintArray(arr, arrLength) ;

	CopyArrayInReverseOrder(arr, arrReversed, arrLength);

	cout << "\nArray 2 : ";
	PrintArray(arrReversed, arrLength);

	return 0;
}