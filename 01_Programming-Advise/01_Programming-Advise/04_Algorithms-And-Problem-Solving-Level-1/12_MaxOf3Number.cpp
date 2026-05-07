#include <iostream>
#include "MyInput.h"
using namespace std;

float MaxOf3Number(float FirstNumber, float SecondNumber, float ThirdNumber)
{
	if (FirstNumber >= SecondNumber)
		return (FirstNumber >= ThirdNumber)? FirstNumber : ThirdNumber;
	else
		return (SecondNumber >= ThirdNumber)? SecondNumber : ThirdNumber;
}


int main()
{
	float FirstNumber = in::ReadFloat("Please enter First Number : ");
	float SecondNumber = in::ReadFloat("Please enter Second Number : ");
	float ThirdNumber = in::ReadFloat("Please enter Third Number : ");
	float Max = MaxOf3Number(FirstNumber, SecondNumber, ThirdNumber);
	cout << Max << endl;

	return 0;
}