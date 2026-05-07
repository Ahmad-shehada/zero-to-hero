#include <iostream>
#include <string>
using namespace std;

struct stData
{
	string GuessPassword = "";
	int Counter = 0;
};

string ReadPassword()
{
	string Password = "";

	cout << "Please enter your Password : ";
	cin >> Password;

	return Password;
}

stData GuessPassword(string Password)
{
	stData Data;

	for (int i = 65; i <= 90; i++)
	{

		for (int j = 65; j <= 90; j++)
		{

			for (int k = 65; k <= 90; k++)
			{
				Data.GuessPassword += char(i);
				Data.GuessPassword += char(j);
				Data.GuessPassword += char(k);

				Data.Counter++;

				if (Password == Data.GuessPassword)
				{
					return Data;
				}
				
				Data.GuessPassword = "";
			}
			
		}

	}

}

void PrintResult(string Password)
{
	stData Data = GuessPassword(Password);

	cout << "\nPassword is " << Data.GuessPassword << "\n";
	cout << "Found After " << Data.Counter << " Trial(s)\n";
}


int main()
{
	PrintResult(ReadPassword());

	return 0;
}