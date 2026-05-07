#include <iostream>
#include <cmath>
#include "MyInput.h"
using namespace std;




double CalculateRectangleArea(double Side, double diagonal)
{
	return Side * sqrt(pow(diagonal, 2) - pow(Side, 2));
}



int main()
{
	double Side = in::ReadDouble("Please enter a side of rectangle : ");
	double diagonal = in::ReadDouble("Please enter a diagonal of rectangle : ");
	double Area = CalculateRectangleArea(Side, diagonal);
	cout << Area << endl;
}