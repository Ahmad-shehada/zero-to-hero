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

void PrintKeys(short noOfKeys, short LengthWord, short LengthText)
{
	for (int i = 1; i <= noOfKeys; i++)
		cout << "Key [" << i << "] : " << GenerateKey(LengthWord, LengthText) << endl;
}


int main()
{
	short LengthWord = in::ReadPositiveIntNumber("Please enter a Length Word : ");
	short LengthText = in::ReadPositiveIntNumber("Please enter a Length Text : ");
	short noOfKeys = in::ReadPositiveIntNumber("Please enter a Number of Keys : ");

	cout << endl;

	PrintKeys(noOfKeys, LengthWord, LengthText);

	return 0;
}