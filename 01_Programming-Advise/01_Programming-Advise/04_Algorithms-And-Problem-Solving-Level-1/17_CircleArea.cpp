#include <iostream>
#include <cmath>
#include "MyMath.h"
#include "MyInput.h"
using namespace std;


double CalculateCircleArea(double Radius)
{
	return math::PI * pow(Radius, 2);
}


int main()
{
	double Radius = in::ReadDouble("Please enter a Radius of Circle : ");
	double Area = CalculateCircleArea(Radius);
	cout << Area << endl;
	
}