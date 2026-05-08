#include <iostream>
#include <cstring>
#include "MyInput.h"
using namespace std;


bool CheckPassword()
{
	const string PIN = "1234";
	string Password = "";
	short Counter = 3;

	do
	{
		Password = in::ReadString("Please enter a Password you have " + to_string(Counter) + " Try : ");

		if (Password == PIN)
			return true;
		else
			Counter--;

	} while (Counter != 0);

	return false;
}

void PrintBalance()
{
	if (CheckPassword())
	{
		system("color 2F");
		cout << "\n Your Balance is 7500\n";
	}
	else
	{
		system("color 4F");
		cout << "\n Sorry you cant Take your card \n";
	}
}

int main()
{
	PrintBalance();
}