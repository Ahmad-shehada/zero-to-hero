#include <iostream>
#include <MyInput.h>
using namespace std;



bool isAccepted(short Age, bool HasDrivingLicense)
{
	return (Age > 21 && HasDrivingLicense);
}

void PrintResult(bool isAccepted)
{
	if (isAccepted)
		cout << "\n Welcom you are Hired\n";
	else
		cout << "\n Sorry you are rejected\n";
}

int main()
{
	short Age = in::ReadShort("Please enter your age : ");
	bool HasDrivingLicense = in::ReadBoolean("are you have Driving License : ");
	bool isAcceptedResult = isAccepted(Age,HasDrivingLicense);
	PrintResult(isAcceptedResult);

	
}