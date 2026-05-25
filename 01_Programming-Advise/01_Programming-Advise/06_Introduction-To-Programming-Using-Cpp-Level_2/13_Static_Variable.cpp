// Static Variable
// Its make the variable lifetime from end function to end program
// This diffention variable one time 
// The variable doesn't store to stack its store in Data Segment
// If a static variable is not explicitly assigned a value, it is automatically initialized to zero, unlike local variable


#include <iostream>
using namespace std;

void Static()
{
	static int x = 0;
	x++;
	cout << x << endl;
}

int main()
{
	Static();
	Static();
	Static();
	Static();
	Static();

	return 0;
}