#include <iostream>
#include "MyInput.h"
using namespace std;



float GetComissionPrecentage(float TotalSalary)
{
	if (TotalSalary >= 1000000)
		return 0.01;
	else if (TotalSalary >= 500000)
		return 0.02;
	else if (TotalSalary >= 100000)
		return 0.03;
	else if (TotalSalary >= 50000)
		return 0.05;
	else
		return 0;
}

float CalculateTotalSalary(float TotalSalary, float ComissionPrecentage)
{
	return ComissionPrecentage * TotalSalary;
}

void PrintPrecentage(float TotalSalary, float FinalTotalSalary, float ComissionPrecentage)
{
	cout << "\n The Precentage of " << TotalSalary << " is " << FinalTotalSalary << "\n";
	cout << " " << ComissionPrecentage << "\n";
}

int main()
{
	float TotalSalary = in::ReadPositiveFloatNumber("Please enter a Positive Number : ");
	float ComissionPrecentage = GetComissionPrecentage(TotalSalary);
	float FinalTotalSalary = CalculateTotalSalary(TotalSalary, ComissionPrecentage);
	PrintPrecentage(TotalSalary, FinalTotalSalary, ComissionPrecentage);


	return 0;
}