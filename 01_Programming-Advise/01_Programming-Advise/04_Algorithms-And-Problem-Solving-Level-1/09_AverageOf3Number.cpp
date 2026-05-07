#include <iostream>
#include <MyInput.h>
using namespace std;

double SumOf3Number(double FirstNumber, double SecondNumber, double ThirdNumber)
{
	return FirstNumber + SecondNumber + ThirdNumber;
}

double AverageOf3Number(double Sum)
{
	return Sum / 3.0;
}

int main()
{
	double FirstNumber = in::ReadDouble("Please enter First Number : ");
	double SecondNumber = in::ReadDouble("Please enter Second Number : ");
	double ThirdNumber = in::ReadDouble("Please enter Third Number : ");
	double Sum = SumOf3Number(FirstNumber, SecondNumber, ThirdNumber);
	double Average = AverageOf3Number(Sum);
	cout << Average << endl;

}