#include <iostream>
#include <MyInput.h>
#include <MyMath.h>
using namespace std;


double CalculateCircleArea(double SideA, double SideB, double SideC)
{
	double SemiPerimeter = (SideA + SideB + SideC) / 2.0;
	double Area = (SideA * SideB * SideC)/(4.0 * sqrt(SemiPerimeter * (SemiPerimeter - SideA) * (SemiPerimeter - SideB) * (SemiPerimeter - SideC)));
	Area = Area * Area *  math::PI;
	return Area;
}


int main()
{
	double SideA = in::ReadDouble("Please enter a Side A : ");
	double SideB = in::ReadDouble("Please enter a Side B : ");
	double SideC = in::ReadDouble("Please enter a Side C : ");
	double Area = CalculateCircleArea(SideA, SideB, SideC);
	cout << Area << endl;
}