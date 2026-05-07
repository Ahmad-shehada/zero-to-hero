#include <iostream>
#include <cmath>
using namespace std;


int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void PrintDigits(int Number)
{
	int Remainder = 0;
	int Temp = 0;
	int Counter = 0;

	cout << "\nThe Digites is :\n";

	while (Number > 0)
	{
		Temp = Number;
		Counter = 0;

		while (Temp > 0)
		{
			Remainder = Temp % 10;
			Temp = int(Temp / 10);
			Counter += 1;

			if (Temp == 0)
			{
				cout << Remainder << endl;
				Number -= Remainder * pow(10, Counter - 1);
			}
		}
		
	}
}



int main()
{
	PrintDigits(ReadPositiveNumber("Please enter a Number : "));

	return 0;
}