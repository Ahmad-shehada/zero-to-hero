#include <iostream>
#include "MyInput.h"
using namespace std;



bool ValidateNumbeInRange(int Number, int From, int To)
{
	return (Number >= From) && (Number <= To);
}


int main()
{
	int Number = in::ReadInt("Please enter your Age : ");
	bool Result = ValidateNumbeInRange(Number, 18, 45);
	
	if (Result)
		cout << "Its a valid Age";
	else
		cout << "Its a invalid Age";
}