#include <iostream>
#include "MyInput.h"
using namespace std;


enum enSecondPerTime { Day = 24*60*60, Hour = 60*60, Minute = 60, Second = 1 };
struct stTime
{
	int Day = 0;
	int Hour = 0;
	int Minute = 0;
	int Second = 0;
};


stTime TimeUnitPerSecond(int Second)
{
	stTime Time;
	int Remainder = 0;

	Time.Day = int(Second / enSecondPerTime::Day);
	Remainder = Second % enSecondPerTime::Day;
	Time.Hour = int(Remainder / enSecondPerTime::Hour);
	Remainder = Remainder % enSecondPerTime::Hour;
	Time.Minute = int(Remainder / enSecondPerTime::Minute);
	Time.Second = Remainder % enSecondPerTime::Minute;

	return Time;
}
void PrintTimeUnit(stTime& Time)
{
	cout << endl <<Time.Day << " : " << Time.Hour << " : " << Time.Minute << " : " << Time.Second << endl;
}


int main()
{
	int Second = in::ReadPositiveIntNumber("Please enter a Number of Seconds : ");
	stTime Time = TimeUnitPerSecond(Second);
	PrintTimeUnit(Time);

	return 0;
}