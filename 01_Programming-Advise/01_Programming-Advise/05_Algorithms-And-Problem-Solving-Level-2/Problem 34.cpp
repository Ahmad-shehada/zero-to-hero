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

void PrintResult(int NumberIndex, int NumberToSearch)
{
	if (NumberIndex >= 0)
	{
		cout << "\nNumber you are Looking for : " << NumberToSearch;
		cout << "\nThe number found at Position : " << NumberIndex;
		cout << "\nThe number found at Orderd : " << NumberIndex + 1 << "\n";
	}
	else
	{
		cout << "\nThe number not Founded ):\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength = ReadPositiveNumber("Please enter a size of Array : ");
	int NumberToSearch;
	short posNumber;
	

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray : ";
	PrintArray(arr, arrLength);

	NumberToSearch = ReadPositiveNumber("\nPlease enter a number to search for : ");
	posNumber = NumberIndex(arr, arrLength, NumberToSearch);

	PrintResult(posNumber, NumberToSearch);

	return 0;
}