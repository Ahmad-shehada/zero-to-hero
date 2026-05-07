#include <iostream>
#include <MyInput.h>
using namespace std;



bool isAccepted(short Age, bool HasDrivingLicense, bool HasRecommendation)
{
	return (Age > 21 && HasDrivingLicense) || (HasRecommendation);
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
	short Age = in::ReadShort("Please enter your Age : ");
	bool HasDrivingLicense = in::ReadBoolean("Are you have Driving License : ");
	bool HasRecommendation = in::ReadBoolean("Are you have Recommendation : ");
	bool isAcceptedResult = isAccepted(Age, HasDrivingLicense, HasRecommendation);
	PrintResult(isAcceptedResult);
	
}