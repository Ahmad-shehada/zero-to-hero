#include <iostream>
#include "MyInput.h"
using namespace std;


enum enMonthOfYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

string GetMonthOfYear(enMonthOfYear DayOfWeek)
{
	string MonthName[12] = { "January", "February", "March", "April", "May", "June", "July", "Auguest", "September", "Octaber", "November", "December" };
	
	return MonthName[DayOfWeek - 1];
}


int main()
{
	enMonthOfYear MonthOfYear = enMonthOfYear(in::ReadIntNumberInRange(1, 12, "Please enter a month 1 / 12 : "));
	string MonthName = GetMonthOfYear(MonthOfYear);
	cout << MonthName << endl;

	return 0;
}