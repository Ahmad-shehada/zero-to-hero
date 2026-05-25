// References
// It's a way to share the same memory location with multiple variables


#include <iostream>
using namespace std;

int z = 10;

// Symbol Table
// Name   Type	Address			  Scope
//  z      int		&z			  Global
//  y      int&		&x(main)       local
//  c      int&		&x(main)       local

void Definition(int& y)
{
	int& c = y;

	cout << "Definition c : " << c << endl;
	cout << "Definition y : " << y << endl;
	
	y = 10;

	cout << "Definition c : " << c << endl;
	cout << "Definition y : " << y << endl;

}

void ReferenceOperator(int& x)
{
	cout << &x << endl; // It's show the address of this variable
}

// Symbol Table
// Name   Type	Address	  Scope
//  z      int		&z	  Global
//  x      int		&x       local


int main()
{
	int x = 5;

	cout << "Main x : " << x << endl;
	Definition(x);
	cout << "Main x : " << x << endl;

	ReferenceOperator(x);

	return 0;
}