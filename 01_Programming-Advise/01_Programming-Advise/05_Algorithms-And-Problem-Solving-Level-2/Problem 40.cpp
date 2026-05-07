#include <iostream>
using namespace std;


void FillArray(int arr[100], int& arrLength)
{
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 10;
	arr[4] = 10;
	arr[5] = 10;
	arr[6] = 10;
	arr[7] = 20;
	arr[8] = 30;
	arr[9] = 10;

	arrLength = 10;
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << ' ';

	cout << endl;
}

short FindNumberPositionInArray(int arr[100], int arrLength, int NumberToSearch)
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
	return FindNumberPositionInArray(arr, arrLength, NumberToFound) != -1;
}

void AddArrayElement(int Number, int arrDestination[100], int& arrLength)
{
	arrDestination[arrLength] = Number;
	arrLength++;
}
void CopyArrayOnlyDistictElement(int arrSource[100], int arrDestination[100], int& arrSourceLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrSourceLength; i++)
		if(!isNumberInArray(arrDestination, arrDestinationLength, arrSource[i]))
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
}



int main()
{
	int arr[100], arrLength = 0;
	int arrDistinct[100], arrDistinctLength = 0;

	FillArray(arr, arrLength);

	cout << "Array 1 : ";
	PrintArray(arr, arrLength);

	CopyArrayOnlyDistictElement(arr, arrDistinct, arrLength, arrDistinctLength);

	cout << "\nArray 2 : ";
	PrintArray(arrDistinct, arrDistinctLength);

	return 0;
}