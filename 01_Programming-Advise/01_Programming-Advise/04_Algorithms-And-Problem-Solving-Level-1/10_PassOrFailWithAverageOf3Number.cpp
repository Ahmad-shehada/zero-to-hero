#include <iostream>
#include "MyInput.h"
using namespace std;

enum enState { Pass = 1, Fail = 2};

double SumOf3Number(double FirstNumber, double SecondNumber, double ThirdNumber)
{
	return FirstNumber + SecondNumber + ThirdNumber;
}

double AverageOf3Number(double Sum)
{
	return Sum / 3.0;
}

enState CheckPass(double Number)
{
	if (Number >= 50)
		return enState::Pass;
	else
	  return enState::Fail;
}

int main()
{
	double FirstNumber = in::ReadDouble("Please enter First Number : ");
	double SecondNumber = in::ReadDouble("Please enter Second Number : ");
	double ThirdNumber = in::ReadDouble("Please enter Third Number : ");
	double Sum = SumOf3Number(FirstNumber, SecondNumber, ThirdNumber);
	double Average = AverageOf3Number(Sum);
	enState State = CheckPass(Average);
	
	if (State == enState::Pass)
		cout << "Pass" << endl;
	else
		cout << "Fail" << endl;

	return 0;

}