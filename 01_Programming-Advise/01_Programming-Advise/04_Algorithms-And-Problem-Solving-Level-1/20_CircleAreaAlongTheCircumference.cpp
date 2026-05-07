#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


double CalculateCircleArea(double Circumference)
{
	return (Circumference * Circumference) / (4.0 * math::PI);
}


int main()
{
	double Circumference = in::ReadDouble("Please enter a circumference of Circle : ");
	double Area = CalculateCircleArea(Circumference);
	cout << Area << endl;
}