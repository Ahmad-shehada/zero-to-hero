#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLeter = 2, SpecialCharacter = 3, Digit = 4 };

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
char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));

	case enCharType::CapitalLeter:
		return char(RandomNumber(65, 90));

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));

	case enCharType::Digit:
		return RandomNumber(48, 57);
	}
}

string GenerateWord(enCharType CharType, short LengthChar)
{
	string Word = "";

	for (int i = 1; i <= LengthChar; i++)
	{
		Word += GetRandomCharacter(CharType);
	}

	return Word;
}
string GenerateKey()
{
	string Key = "";
	const short Length = 4;

	for (int i = 1; i <= Length; i++)
	{
		Key += GenerateWord(enCharType::CapitalLeter, 4);

		if (i != Length)
			Key += '_';
	}

	return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateKey();
	}
}
void PrintArray(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << "Array [" << i + 1 << "] : " << arr[i] << "\n";

	cout << endl;
}


int main()
{
	srand((unsigned)time(NULL));

	int arrLength = ReadPositiveNumber("Please enter a Size of Array : ");
	string arr[100];

	cout << endl;

	FillArrayWithKeys(arr, arrLength);
	PrintArray(arr, arrLength);

	return 0;
}