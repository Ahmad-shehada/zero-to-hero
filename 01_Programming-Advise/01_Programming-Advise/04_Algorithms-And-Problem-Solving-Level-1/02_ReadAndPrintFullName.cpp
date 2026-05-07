#include <iostream>
#include "MyInput.h"
using namespace std;


void PrintFullName(const string& FullName)
{
	cout << "\nYour name is " << FullName << "\n";
}

int main()
{
	string FullName = in::ReadString("Please enter your Full Name : ");
	PrintFullName(FullName);
}