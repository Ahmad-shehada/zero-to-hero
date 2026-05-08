#include <iostream>
#include "MyInput.h"
using namespace std;

char GetGradeLetter(float Mark)
{
	if (Mark >= 90)
		return 'A';
	else if (Mark >= 80)
		return 'B';
	else if (Mark >= 70)
		return 'C';
	else if (Mark >= 60)
		return 'D';
	else if (Mark >= 50)
		return 'E';
	else
		return 'F';
}

int main()
{
	float Mark = in::ReadFloatNumberInRange(0, 100, "Please enter your mark : ");
	char Grade = GetGradeLetter(Mark);
	
	cout << "The Grade is " << Grade << endl;
}