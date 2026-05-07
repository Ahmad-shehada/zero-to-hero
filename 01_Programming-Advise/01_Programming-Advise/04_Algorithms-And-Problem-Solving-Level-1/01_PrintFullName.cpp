#include <iostream>
using namespace std;

// Passing by reference (&) to avoid unnecessary memory copying using (8 byte instead of 40 byte)
// Using 'const' to ensure the original data remains unchanged

void PrintFullName(const string& FullName)
{
	cout << "Your name is " << FullName << "\n";
}

int main()
{
	string FullName = "Ahmad Shehada";
	PrintFullName(FullName);

	return 0;
}