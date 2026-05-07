#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a Number : ";
	cin >> Number;

	return Number;
}

void PrintResult(int Number)
{
	cout << " Power 2 : " << Number * Number << "\n";
	cout << " Power 3 : " << Number * Number * Number << "\n";
	cout << " Power 4 : " << Number * Number * Number * Number << "\n";
}


int main()
{
	PrintResult(ReadNumber());
}