#include <iostream>
#include <MyInput.h>
#include "MyRandom.h"
using namespace std;

string GenerateKey(short LengthWord, short LengthText)
{
	string Key = "";

	for (int i = 1; i <= LengthText; i++)
	{
		Key += random::GenerateWord(random::enCharType::CapitalLeter, LengthWord);

		if (i != LengthText)
			Key += '_';
	}

	return Key;
}
void FillArrayWithKeys(string arr[], int arrLength, short LengthWord, short LengthText)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = GenerateKey(LengthWord, LengthText);
}
void PrintKeys(string arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << "Key [" << i + 1 << "] : " << arr[i] << endl;
}

int main()
{
	string arr[100];
	int arrLength = in::ReadPositiveIntNumber("Please enter a arr Length : ");
	short LengthWord = in::ReadPositiveIntNumber("Please enter a Length Word : ");
	short LengthText = in::ReadPositiveIntNumber("Please enter a Length Text : ");

	cout << endl;

	FillArrayWithKeys(arr, arrLength, LengthWord, LengthText);
	PrintKeys(arr, arrLength);

	return 0;
}