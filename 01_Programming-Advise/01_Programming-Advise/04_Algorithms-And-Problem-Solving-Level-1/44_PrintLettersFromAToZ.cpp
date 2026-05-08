#include <iostream>
using namespace std;

void PrintLetterAToZ()
{
	int Counter = 65;
	int Limit = 90;

	for (int i = Counter; i <= Limit; i++)
	{
		cout << char(i) << endl;
	}

}

int main()
{
	PrintLetterAToZ();
}