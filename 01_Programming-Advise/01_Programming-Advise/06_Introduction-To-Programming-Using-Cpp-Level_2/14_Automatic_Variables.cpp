// Automatic Variables
// It must be initialized at the time of definition.


#include <iostream>
using namespace std;

// How to use
void HowToUse()
{
	auto x = 5; // Automatic converst type to int
	auto y = 5.0f; // Automatic converst type to float
	auto z = 5.0; // Automatic converst type to double
	auto w = 'A'; // Automatic converst type to char
	auto f = "ahmadsa"; // Automatic converst type to const char*
	auto q = string("Ahmad"); // Automatic converst type to string
}


int main()
{

	HowToUse();

	return 0;
}