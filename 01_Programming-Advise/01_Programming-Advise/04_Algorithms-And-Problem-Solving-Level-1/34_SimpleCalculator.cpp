#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


int main()
{
	double FirstNumber = in::ReadDouble("Please enter first Number : ");
	double SecondNumber = in::ReadDouble("Please enter Second Number : ");
	math::enOperator Operator = math::enOperator(in::ReadChar("Please enter operator (+, -, *, /) : "));
	double Result = math::SimpleCalculate(FirstNumber, SecondNumber, Operator);
	
	cout << "The Result is " << Result << endl;
	
	return 0;
}