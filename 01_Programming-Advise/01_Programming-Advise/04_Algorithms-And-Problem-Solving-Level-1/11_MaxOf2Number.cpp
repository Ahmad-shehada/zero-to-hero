#include <iostream>
#include <MyInput.h>
using namespace std;

float MaxOf2Number(float FirstNumber, float SecondNumber)
{
	return (FirstNumber >= SecondNumber)? FirstNumber : SecondNumber;
}


int main()
{
	float FirstNumber = in::ReadFloat("Please enter First Number : ");
	float SecondNumber = in::ReadFloat("Please enter Second Number : ");
	float Max = MaxOf2Number(FirstNumber, SecondNumber);
	cout << Max << endl;

	return 0;
}