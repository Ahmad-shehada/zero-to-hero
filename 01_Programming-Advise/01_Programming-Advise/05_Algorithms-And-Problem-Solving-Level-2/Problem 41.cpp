#include <iostream>
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
bool ReadChoice()
{
	int Choice;

	do
	{
		cout << "Do yo want to add more Numbers [0]No,[1]Yes :  ";
		cin >> Choice;

	} while (Choice != 1 && Choice != 0);

	return bool(Choice);
}

void AddArrayElement(int arr[100], int& arrLength)
{
	arr[arrLength] = ReadPositiveNumber("Please enter a Number : ");
	arrLength++;
}
void InputUserNumberInArray(int arr[100], int& arrLength)
{
	do
	{
		AddArrayElement(arr, arrLength);

	} while (ReadChoice());
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << ' ';

	cout << endl;
}

bool isPlindromeArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] != arr[arrLength - i - 1])
			return false;
	}

	return true;
}

int main()
{
	int arr[100], arrLength = 0;
	int arrReversed[100];

	InputUserNumberInArray(arr, arrLength);

	cout << "\nArray 1 : ";
	PrintArray(arr, arrLength);

	if (isPlindromeArray(arr, arrLength))
		cout << "\nIts Plindrome Array \n";
	else
		cout << "\nIts not Plindrome Array \n";

	return 0;
}