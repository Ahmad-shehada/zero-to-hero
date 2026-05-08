#include <iostream>
#include "MyInput.h"
using namespace std;



bool CheckPassword()
{
	const string PIN = "1234";
	string Message = "Please enter a Password : ";
	string Password = "";

	do
	{
		if (Password == PIN)
			return true;
		else
		{
			Password = in::ReadString(Message);
			Message = "Wrong Password Please try again : ";
			system("color 4F");
		}

	} while (true);

	
}

void PrintBalance()
{
	if (CheckPassword())
	{
		system("color 2F");
		cout << "\n Your Balance is 7500\n";
	}
}

int main()
{
	PrintBalance();
}