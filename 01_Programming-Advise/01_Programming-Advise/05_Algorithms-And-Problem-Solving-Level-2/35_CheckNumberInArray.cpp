#include <iostream>
#include "MyInput.h"
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

int main()
{
	int arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a Array Length : ");
	int NumberToSearch = 0;

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	NumberToSearch = in::ReadIntNumberInRange(1, 100, "Please enter a Number To Search : ");

	cout << "\nNumber your are looking for is " << NumberToSearch << endl;
	if (isNumberInArray(arr, arrLength, NumberToSearch))
		cout << "Yes, The Number is founded" << endl;
	else
		cout << "The Number is not founded" << endl;

	return 0;
}