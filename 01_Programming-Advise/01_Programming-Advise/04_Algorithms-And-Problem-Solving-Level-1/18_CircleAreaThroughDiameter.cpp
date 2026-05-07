#include <iostream>
#include <MyInput.h>
#include <MyMath.h>
using namespace std;

double CalculateCircleArea(double Diameter)
{
	return (math::PI * Diameter * Diameter) / (4);
}


int main()
{
	double Diameter = in::ReadDouble("Please enter a diameter of circle : ");
	double Area = CalculateCircleArea(Diameter);
	cout << Area << endl;
}