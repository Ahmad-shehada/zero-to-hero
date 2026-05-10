#include <iostream>
#include "MyRandom.h"
using namespace std;


int main()
{
	cout << random::RandomCharacter(random::enCharType::SmallLetter) << endl;
	cout << random::RandomCharacter(random::enCharType::CapitalLeter) << endl;
	cout << random::RandomCharacter(random::enCharType::SpecialCharacter) << endl;
	cout << random::RandomCharacter(random::enCharType::Digit) << endl;
	
	return 0;
}