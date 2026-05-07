#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLeter = 2, SpecialCharacter = 3, Digit = 4 };

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

void GenerateKeys(short Number)
{
	for (int i = 1; i <= Number; i++)
		cout << "Key [" << i << "] : " << GenerateKey() << endl;

}

int main()
{
	srand(time(NULL));

	GenerateKeys(ReadPositiveNumber("Please enter a Number of Key : "));

	return 0;
}