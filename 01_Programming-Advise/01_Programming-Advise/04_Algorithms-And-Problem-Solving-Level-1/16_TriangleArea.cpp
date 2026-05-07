#include <iostream>
#include "MyInput.h"
using namespace std;

double CalculateTriangleArea(double Base, double Height)
{
	return (0.5 * Base * Height);
}


int main()
{
	double Base = in::ReadDouble("Please enter a Base of Triangle : ");
	double Height = in::ReadDouble("Please enter a Height of Triangle : ");
	double Area = CalculateTriangleArea(Base, Height);
	cout << Area << endl;
}