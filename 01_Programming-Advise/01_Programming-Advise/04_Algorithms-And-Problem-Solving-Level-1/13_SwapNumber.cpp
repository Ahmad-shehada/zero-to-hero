#include <iostream>
#include "MyInput.h"
using namespace std;


void Swap(float& FirstNumber, float& SecondNumber)
{
	float Temp = FirstNumber;
	FirstNumber = SecondNumber;
	SecondNumber = Temp;
}



int main()
{
	float FirstNumber = in::ReadFloat("Please enter First Number : ");
	float SecondNumber = in::ReadFloat("Please enter Second Number : ");
	Swap(FirstNumber, SecondNumber);
	cout << "FirstNumber is " << FirstNumber << endl;
	cout << "SecondNumber is " << SecondNumber << endl;
}