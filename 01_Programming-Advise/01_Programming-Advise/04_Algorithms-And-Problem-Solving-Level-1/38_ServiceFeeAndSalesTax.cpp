#include <iostream>
#include "MyInput.h"
using namespace std;


float TotalBillAfterServiceAndTax(float BillValue)
{
	return ((BillValue * 1.1) * 1.16);
}
void PrintTotalBill(float BillValue)
{
	cout << "\n The Total Bill is " << TotalBillAfterServiceAndTax(BillValue) << "\n";
}

int main()
{
	float BileValue = in::ReadPositiveFloatNumber("Please enter Bill Value : ");
	PrintTotalBill(BileValue);

	return 0;
}