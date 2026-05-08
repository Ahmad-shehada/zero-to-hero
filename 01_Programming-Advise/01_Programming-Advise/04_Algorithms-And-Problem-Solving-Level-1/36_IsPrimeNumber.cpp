#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;


int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	bool isPrime = math::isPrime(Number);

	if (isPrime)
		cout << "The Number is Prime" << endl;
	else
		cout << "The Number isn't Prime" << endl;
}