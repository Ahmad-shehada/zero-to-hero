#include <iostream>
#include "MyInput.h"
using namespace std;

float DayPerHours(int Hours)
{
	return (Hours / 24.0);
}

float WeekPerHours(int Hours)
{
	return (DayPerHours(Hours) / 7.0);
}

void PrintDayAndHours(int Hours)
{
	cout << "\n The Day per Hours is " << DayPerHours(Hours) << endl;
	cout << "\n The Week per Hours is " << WeekPerHours(Hours) << endl;
}


int main()
{
	int Hours = in::ReadPositiveIntNumber("How many Hours : ");
	PrintDayAndHours(Hours);
}