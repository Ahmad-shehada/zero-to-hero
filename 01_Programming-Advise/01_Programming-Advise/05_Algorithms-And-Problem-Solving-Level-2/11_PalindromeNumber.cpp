#include <iostream>
#include "MyInput.h"
#include "MyMath.h"
using namespace std;
 

int main()
{
	int Number = in::ReadPositiveIntNumber("Please enter a Number : ");
	
	if (math::isPalindrome(Number))
		cout << "Its Palindrome Number\n";
	else
		cout << "Its not Palindrome Number\n";

	return 0;
}