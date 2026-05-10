#include <iostream>
#include "MyInput.h"
using namespace std;


string GetGuessPassword(string& Password, int& Counter)
{
	string GuessPassword = "";

	for (int i = 65; i <= 90; i++)
		for (int j = 65; j <= 90; j++)
			for (int k = 65; k <= 90; k++)
			{
				Counter++;

				GuessPassword = string("") + char(i) + char(j) + char(k);

				cout << "Trial [" << Counter << "] : " << GuessPassword << "\n";

				if (Password == GuessPassword)
					return GuessPassword;
			}

	return "Not Found";
}


int main()
{
	string Password = in::ReadString("Please enter a 3 Letter : ");
	int Counter = 0;
	string GuessPassword = GetGuessPassword(Password, Counter);

	cout << "\nPassword is " << GuessPassword  << endl;
	cout << "Found after " << Counter << " Trial(s)" << endl;

	return 0;
}