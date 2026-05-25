// Recursion
// The the function call its self
// You should be careful from use the feature to avoid stack overflow

#include <iostream>
#include <cmath>
using namespace std;

// Error
void Function_1(int Number) // Error Stack Overflow : becase you reach a Limit
{
	cout << Number << endl;
	Function_1(Number + 1);
}

int main()
{
	
	

	return 0;
}