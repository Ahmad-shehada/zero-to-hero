#include <iostream>
#include "MyInput.h"
using namespace std;


enum enDayOfWeek { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

string GetDayOfWeek(enDayOfWeek DayOfWeek)
{
	string DayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return DayName[DayOfWeek - 1];
}


int main()
{
	enDayOfWeek DayOfWeek = enDayOfWeek(in::ReadIntNumberInRange(1, 7, "Please enetr a day of week 1 / 7 : "));
	string DayName = GetDayOfWeek(DayOfWeek);
	cout << DayName << endl;

	return 0;
}