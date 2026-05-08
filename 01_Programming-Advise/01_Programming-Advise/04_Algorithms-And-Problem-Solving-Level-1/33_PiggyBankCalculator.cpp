#include <iostream>
#include "MyInput.h"
using namespace std;

enum enMoneyType {Penny = 1, Nickel = 5, Dime = 10, Quarter = 25, Dollar = 100};

struct stMoneyTypeCount
{
	int Penny, Nickel, Dime, Quarter, Dollar;
};

stMoneyTypeCount ReadAmountOfMoney()
{
	stMoneyTypeCount MoneyCount;

	MoneyCount.Penny = in::ReadPositiveIntNumber("Please enter How Many Penny : ");
	MoneyCount.Nickel = in::ReadPositiveIntNumber("Please enter How Many Nickel : ");
	MoneyCount.Dime = in::ReadPositiveIntNumber("Please enter How Many Dime : ");
	MoneyCount.Quarter = in::ReadPositiveIntNumber("Please enter How Many Quarter : ");
	MoneyCount.Dollar = in::ReadPositiveIntNumber("Please enter How Many Dollar : ");

	return MoneyCount;
}

int CalculateTotalMoney(stMoneyTypeCount MoneyTypeCount)
{
	int TotalPenneis = (MoneyTypeCount.Dollar * enMoneyType::Dollar) + (MoneyTypeCount.Quarter * enMoneyType::Quarter) +
		(MoneyTypeCount.Dime * enMoneyType::Dime) + (MoneyTypeCount.Nickel * enMoneyType::Nickel) + (MoneyTypeCount.Penny);

	return TotalPenneis;
}

void PrintTotalMoney(stMoneyTypeCount MoneyType)
{
	int TotalMoney = CalculateTotalMoney(MoneyType);

	cout << "\n The total Money in Penny is " << TotalMoney << "\n";
	cout << "\n The total Money in Dollar is " << TotalMoney / 100.0<< "$\n";
}

int main()
{
	PrintTotalMoney(ReadAmountOfMoney());
}