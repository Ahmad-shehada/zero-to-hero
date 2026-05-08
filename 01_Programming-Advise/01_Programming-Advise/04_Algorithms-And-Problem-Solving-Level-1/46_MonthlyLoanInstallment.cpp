#include <iostream>
#include "MyInput.h"
using namespace std;


float GetTotalSalary(float LoanAmount, float MonthAmount)
{
	return (LoanAmount / MonthAmount);
}

int main()
{
	float LoanAmount = in::ReadPositiveFloatNumber("Please enter Loan Amount : ");
	float MonthAmount = in::ReadPositiveFloatNumber("Please enter Month Amount : ");

	cout << "\n The Number of Salary " << GetTotalSalary(LoanAmount, MonthAmount) << "$" << endl;
}