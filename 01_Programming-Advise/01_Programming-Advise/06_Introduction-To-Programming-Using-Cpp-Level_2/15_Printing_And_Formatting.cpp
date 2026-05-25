// Printing & Formatting
// %AnyChar is Format Specifier(Placeholder)


#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


void Integer()
{
	short Num1 = 1;
	int Num2 = 2;
	long int Num3 = 3;
	long long int Num4 = 4;

// print int variable
	// You can use 'd' (Decimal Integer) or 'i' (Integer)
	printf("Num1 = %hd \n", Num1);// Stand of Half Decimal Integer (only take 2 byte)
	printf("Num2 = %d \n", Num2);// Stand of Decimal Integer (only take 4 byte)
	printf("Num3 = %ld \n", Num3);// Stand of Long Decimal Integer (only take 4 byte)
	printf("Num4 = %lld \n", Num4);// Stand of Long Long Decimal Integer (only take 8 byte)

// width specification
	printf("%02d Course\n", 1);
	printf("%3d Course\n", 1);
	printf("%*d Course\n", 2, 1);
	printf("%0*d Course\n", 3, 1);

	// Padding Position
		// Use '0' for zero-padding or nothing for space-padding

	// Width Position
		// Defines the text width
		// Accepts a numerical value for width 
		// The '*' character makes the width dynamic rather than static

// Problems
	int x = 0x7fffffff;
	printf("The problem 1 %hd \n", x); // Because it's only take 2 byte not 4
	printf("The problem 2 %d \n", 1.823); // Because you are breakin the contract 

}

void FloatAndDouble()
{
	float Num_1 = 23.12;
	double Num_2 = 12.12;

// Print Float and Double Numbers
	printf("%f \n", Num_1); // Stand of Floating-point (only take 4 byte)
	printf("%lf \n", Num_2); // Stand of Long Floating-point (only take 8 byte)

// Precision specification
	printf("%.*f \n", 2, 3.0);

	// Start of Precision
		// It's say to compilar, I am in fraction side

	// Precision Field
		// Defines the Number Precision
		// Accepts a numerical value for Precision 
		// The '*' character makes the Precision dynamic rather than static

// Round method in printf : 
	printf("%.*lf \n", 5, 7.123456789); // It's happen becase it's automaticly make round in the last fraction
	printf("%.*lf \n", 7, 7.123456789); // It's happen becase it's automaticly make round in the last fraction

// Problem
	printf("%f \n", 45); // Because you are breakin the contract
	printf("%.15f \n", 1.123456789012345f); // Because the limit of precision float variable is 6

}

void StringAndChar()
{
	char Name[] = "Ahmad Shehada"; // The printf method doesn't handle with std::string object
	char Gender = 'M';

// print String and char variable
	printf("%s \n", Name); // stand of String
	printf("%c \n", Gender); // Stand of Character

// width specification
	char x = 'A';

	printf("%*c \n", 2, x);
	printf("%*c \n", 3, x);
	printf("%4c \n", x);

	// Width Position
		// Defines the text width
		// Accepts a numerical value for width 
		// The '*' character makes the width dynamic rather than static

// Alignment
	printf("%-*c Hello \n", 5, 'A'); // Left Alignment
	printf("%-*s Hello \n", 10, "C++");
	printf("%*c Hello \n", 5, 'A'); // Right Alignment
	printf("%*s Hello \n", 10, "C++");

// Problem
	//printf("%s", 'A'); // will throw error
	printf("%c", "asajssjjkb");
}

void Setw()
{
// How to use
	cout << setw(10) << "Ahmad" << " dds" << endl; // Stand of Set Width

// Alignment
	cout << left << setw(10) << "Ahmad" << " dds" << endl; // Left Alignment
	cout << right << setw(10) << "Ahmad" << " dds" << endl; // Right Alignment (Default)
	// one call enough for change all alignment state

}



int main()
{
	FloatAndDouble();
	return 0;
}