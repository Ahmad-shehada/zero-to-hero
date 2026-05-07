#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


double CalculateCircleArea(double Side, double Base)
{
	return math::PI * (Base * Base / 4.0) * ((2.0 * Side - Base) / (2.0 * Side + Base));
}


int main()
{
	double Side = in::ReadDouble("Please enter a Side : ");
	double Base = in::ReadDouble("Please enter a Base : ");
	double Area = CalculateCircleArea(Side, Base);
	cout << Area << endl;
}