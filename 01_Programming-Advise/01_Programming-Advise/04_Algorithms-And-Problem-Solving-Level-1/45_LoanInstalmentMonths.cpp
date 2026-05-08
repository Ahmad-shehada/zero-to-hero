#include <iostream>
#include "MyInput.h"
using namespace std;


float GetMonth(float LoanAmount, float MonthlyPayment)
{
	return (LoanAmount / MonthlyPayment);
}

int main()
{
	float LoanAmount = in::ReadPositiveFloatNumber("Please enter Loan Amount : ");
	float MonthlyPayment = in::ReadPositiveFloatNumber("Please enter Monthly Payment : ");

	cout << "\n The Number of Month is " << GetMonth(LoanAmount, MonthlyPayment) << " Month" << endl;
}