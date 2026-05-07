#include <iostream>
#include <string>
using namespace std;

void PrintHeaderTable()
{
	cout << "\n\n\t\t\tMultiplication Table From 1 To 10\n\n";

	for (int i = 1; i <= 10; i++)
	{
		cout << "\t" << i;
	}

	cout << "\n_______________________________________________________________________________________\n";
}

string ColumSperator(int i)
{
	if (i < 10)
		return "  |";
	else
		return " |";
}

void PrintMultiplicationTable()
{
	PrintHeaderTable();

	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumSperator(i);

		for (int j = 1; j <= 10; j++)
		{
			cout << "\t" << i * j;
		}
		cout << "\n";
	}

}

int main()
{
	PrintMultiplicationTable();
}
