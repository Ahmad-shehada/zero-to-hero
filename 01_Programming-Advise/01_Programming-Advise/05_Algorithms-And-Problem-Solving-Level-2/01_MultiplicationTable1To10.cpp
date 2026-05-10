#include <iostream>
#include <string>
using namespace std;

void HeaderTable()
{
	cout << "\n\n\t\t\t    Multiplication Table From 1 To 10\n\n";
	
	for (int i = 1; i <= 10; i++)
		cout << "\t" << i;

	cout << "\n____________________________________________________________________________________\n";
}
string CoulmSperator(int RowNumber)
{
	if (RowNumber == 10)
		return to_string(RowNumber) + "   |  ";
	else
		return to_string(RowNumber) + "    |  ";
}
void BodyTable()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << CoulmSperator(i);

		for (int j = 1; j <= 10; j++)
			cout << i * j << "\t";

		cout << "\n";
	}

}


int main()
{
	HeaderTable();
	BodyTable();
}
