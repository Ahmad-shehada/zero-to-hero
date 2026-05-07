#include <iostream>
#include <cstdlib>
using namespace std;


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}



int main()
{
	srand(time(NULL));

	for (int i = 1; i <= 3; i++)
	{
		cout << RandomNumber(1, 10) << endl;
	}

	return 0;
}