//Default Paramters
//To make fill parameter optional

#include <iostream>
using namespace std;

//problem
// happen error because you must fill parameters( right to left) and don't miss any parameter in a center
void Hello_1(int x, int y = 0, int z, int w = 0)
{
	cout << x + y + z + w << endl;
}
void Hello_2(int x = 0, int y = 0, int z = 0, int w)
{
	cout << x + y + z + w << endl;
}

//Usage
void Hello(int x, int y = 0, int z = 0, int w = 0)
{
	cout << x + y + z + w << endl;
}
int main()
{
	Hello(1);
	Hello(1, 5);
	Hello(1, 5, 10);
	Hello(1, 5, 10, 15);
	Hello_1(1, 2, 3, 4);
	Hello_2(1, 2, 3, 4);

	return 0;
}