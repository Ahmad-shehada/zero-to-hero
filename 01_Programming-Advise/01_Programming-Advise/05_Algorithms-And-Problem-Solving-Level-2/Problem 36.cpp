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
		cout << "\nDo yo want to add more Numbers [0]No,[1]Yes :  ";
		cin >> Choice;

	} while (Choice != 1 && Choice != 0);

	return bool(Choice);
}

void AddArrayElement(int arr[100], int& arrLength)
{
	arr[arrLength] = ReadPositiveNumber("\nPlease enter a Number : ");
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


int main()
{
	int arr[100];
	int arrLength = 0;

	InputUserNumberInArray(arr, arrLength);

	cout << "\nArray Length : " << arrLength;
	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	return 0;
}