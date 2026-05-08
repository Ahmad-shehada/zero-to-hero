#include <iostream>
#include "MyInput.h"
using namespace std;


float CalcualteRemainder(float TotalBill, float CashPaid)
{
	return (CashPaid - TotalBill);
}

void PrintRemainder(float Remainder)
{
	cout << "\n The Remainder is " << Remainder << "\n";
}

int main()
{
	float TotalBill = in::ReadPositiveFloatNumber("Please enter Total Bill : ");
	float CashPaid = in::ReadPositiveFloatNumber("Please enter Cash Paid : ");
	float Remainder = CalcualteRemainder(TotalBill, CashPaid);

	PrintRemainder(Remainder);

	return 0;
}