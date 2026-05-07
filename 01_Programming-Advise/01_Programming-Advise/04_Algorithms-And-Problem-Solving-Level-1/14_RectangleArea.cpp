#include <iostream>
#include "MyInput.h"
using namespace std;

double CalculateRectangleArea(double Width, double Height)
{
	return Width * Height;
}

int main()
{
	double Width = in::ReadDouble("Please enter a Width : ");
	double Height = in::ReadDouble("Please enter a Hieght : ");
	double Area = CalculateRectangleArea(Width, Height);
	cout << Area << endl;
}