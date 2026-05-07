#include <iostream>
#include <cstdlib>
using namespace std;


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enum enCharType { SmallLetter = 1, CapitalLeter = 2, SpecialCharacter = 3, Digit = 4 };
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

int main()
{
	srand(time(NULL));

	cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
	cout << GetRandomCharacter(enCharType::CapitalLeter) << endl;
	cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;

	return 0;
}