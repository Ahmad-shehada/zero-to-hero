#include <iostream>
#include <MyInput.h>
#include <MyMath.h>
using namespace std;


double CalculateCircleArea(double Side)
{
	return (math::PI * Side * Side) / (4.0);
}


int main()
{
	double Side = in::ReadDouble("Please enter a Side of the square : ");
	double Area = CalculateCircleArea(Side);
	cout << Area << endl;
	
}