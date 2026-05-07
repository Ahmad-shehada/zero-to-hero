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

short NumberIndex(int arr[100], int arrLength, int NumberToSearch)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (NumberToSearch == arr[i])
		{
			return i;
		}
	}

	return -1;
}

bool isNumberInArray(int arr[100], int arrLength, int NumberToFound)
{
	return NumberIndex(arr, arrLength, NumberToFound) != -1;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength = ReadPositiveNumber("Please enter a size of Array : ");
	int NumberToFound;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray : ";
	PrintArray(arr, arrLength);

	NumberToFound = ReadPositiveNumber("\nPlease enter Numebr to found : ");

	cout << "\nNumber you are looking for : " << NumberToFound << "\n";
	if (isNumberInArray(arr, arrLength, NumberToFound))
		cout << "Yes, The Number is Founded (:\n";
	else
		cout << "No, The Number is not Founded ):\n";

	return 0;
}