#include <iostream>
#include "MyInput.h"
using namespace std;


int main()
{
	int Number = in::ReadIntNumberInRange(18, 45, "Please enter a Number : ");
	cout << Number << endl;

	return 0;
}