#include <iostream>
#include "MyRandom.h"
using namespace std;


int main()
{
	for (int i = 1; i <= 3; i++)
		cout << random::RandomNumber(1, 10) << endl;

	return 0;
}