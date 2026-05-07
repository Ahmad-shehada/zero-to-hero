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

bool isPrime(int Number)
{
	int Limit = ceil(Number / 2.0);

	for (int i = 2; i <= Limit; i++)
	{
		if (Number % i == 0)
			return false;
	}

	return true;
}
void CopyArrayOnlyPrime(int arrSource[100], int arrDestination[100], int& arrLength)
{
	int Counter = 0;

	for (int i = 0; i < arrLength; i++)
		if (isPrime(arrSource[i]))
		{
			arrDestination[Counter] = arrSource[i];
			Counter++;
		}

	arrLength = Counter;
}

int main()
{
	srand(time(NULL));

	int arrLength = ReadPositiveNumber("Enter Number of Element : ");
	int arr_1[100];
	int arr_2[100];

	FillArrayWithRandomNumber(arr_1, arrLength);

	cout << "\nArray 1 Element : ";
	PrintArray(arr_1, arrLength);

	CopyArrayOnlyPrime(arr_1, arr_2, arrLength);

	cout << "\nArray 2 Element : ";
	PrintArray(arr_2, arrLength);

	return 0;
}