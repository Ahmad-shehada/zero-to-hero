//Ranged Loop
//Its a type of for loop
//It uses for the colection variable like (Array, vector)
//Its must know a Begin and End Index

#include <iostream>
using namespace std;

void problem(int x[])
{
	//Its happen error because the array is a pointer it can't definition End Array
	/*for (int& n : x) 
	{
		n = 5;
	}*/
}
void Advance()
{
	int x[] = { 1, 2, 3, 4, 5, 6, 4, 6, 6 };

	//Its does't need the size of array
	for (int n : x)//by value
	{
		cout << n << endl;
	}

	for (int& n : x)//by Ref
	{
		cout << n << endl;
	}
}
void HowCompilarRead()
{
	int x[] = { 1,2,3,4,5,6,7,1,1,2,3 };

	for (int n : x)
	{
		cout << n << endl;
	}

	//Definition Begin = x
	//Definition End = x + size
	//Make for loop
}

int main()
{

	

	return 0;
}