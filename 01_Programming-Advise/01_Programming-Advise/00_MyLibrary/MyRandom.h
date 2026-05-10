#pragma once

#include <ctime>
#include <cstdlib>
using namespace std;

namespace random
{
	enum enCharType { SmallLetter = 1, CapitalLeter = 2, SpecialCharacter = 3, Digit = 4 };

	bool InitializeSeed()
	{
		srand((unsigned)time(NULL));
		return true;
	}
	bool is_Seeded = InitializeSeed();

	int RandomNumber(int From, int To)
	{	
		return rand() % (To - From + 1) + From;
	}

	char RandomCharacter(enCharType CharType)
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
			return char(RandomNumber(48, 57));

		default:
			return char(RandomNumber(33, 122));
		}

	}

	string GenerateWord(enCharType CharType, short LengthWord)
	{
		string Word = "";

		for (int i = 1; i <= LengthWord; i++)
		{
			Word += RandomCharacter(enCharType::CapitalLeter);
		}
		
		return Word;
	}

}
