// Function Overloading
// using to definition more than one parameter have the same name

// Rule
// The functions must have a different number or a different data type or different order of parameter
// The different return value or changed parameter name doesn't allow to make a function overloading

#include <iostream>
using namespace std;

void Read(int x, double y)
{
	cout << "This is int double\n";
}
void Read(double x, int y)
{
	cout << "This is double int\n";
}

void Write(int x)
{
	cout << "not default parameter\n";
}
void Write(int x, int y = 1)
{
	cout << "default parameter\n";
}

int main()
{
	Read(1, 1.0);
	Read(1.0, 1);
	Read(1.0, 1.0);// happen error because the compilar doesn't now what the function we use

	Write(1, 1);
	Write(1);// happen error because the compilar doesn't now what the function we use

	return 0;
}