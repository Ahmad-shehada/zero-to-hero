#include <iostream>
#include "MyInput.h"
using namespace std;


enum enSecondPerTime {Day = 24*60*60, Hour = 60*60, Minute = 60, Second = 1};
struct stTime
{
	int Day = 0;
	int Hour = 0;
	int Minute = 0;
	int Second = 0;
};


stTime ReadTime()
{
	stTime Time;

	Time.Day = in::ReadPositiveIntNumber("Please enter Number Of Day : ");
	Time.Hour = in::ReadPositiveIntNumber("Please enter Number Of Hour : ");
	Time.Minute = in::ReadPositiveIntNumber("Please enter Number Of Minute : ");
	Time.Second = in::ReadPositiveIntNumber("Please enter Number Of Second : ");

	return Time;
}

int SecondPerTime(stTime& Time)
{
	int TotalSecond = (Time.Day * enSecondPerTime::Day) + (Time.Hour * enSecondPerTime::Hour)
		+ (Time.Minute * enSecondPerTime::Minute) + (Time.Second);

	return TotalSecond;
}

void PrintTotalSecond(stTime& Time)
{
	cout << "\n The Total Second is " << SecondPerTime(Time) << endl;
}


int main()
{

	stTime Time = ReadTime();
	PrintTotalSecond(Time);

	return 0;
}