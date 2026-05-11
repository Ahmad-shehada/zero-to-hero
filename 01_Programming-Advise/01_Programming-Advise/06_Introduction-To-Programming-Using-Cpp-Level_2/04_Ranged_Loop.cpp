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

//Problem Solving

void PriceProcessor()
{
	double Salary[10] = { 10.0, 5.0, 99.0, 50.2, 90.5, 40.3, 10.2, 100, 200, 150 };

	for (const double n : Salary)
		cout << n << " ";
	cout << endl;

	for (double& n : Salary)
		if (n < 50)
			n *= 1.1;
		else if (n >= 100)
			n -= 5;

	for (const double n : Salary)
		cout << n << " ";
	cout << endl;
}
void TemperatureMonitor()
{
	double x[] = { 22.5, 45.2, 18.0, 31.5, 48.0, 15.2, 28.0 };
	double Sum = 0;
	double Average = 0;
	short Counter = 0;

	for (const double n : x)
		cout << n << " ";
	cout << endl;

	for (const double n : x)
	{
		Sum += n;
		Counter++;
	}

	Average = Sum / Counter;
	cout << "The Average is " << Average << endl;

	for (double& n : x)
		if (n > 40)
			n -= 5;

	for (const double n : x)
		cout << n << " ";
	cout << endl;

}
void GradeProcess()
{
	int x[] = { 75, 42, 88, 30, 95, 49, 60 };

	for (const int n : x)
		cout << n << " ";
	cout << endl;

	for (int& n : x)
		n = (n < 50) ? 0 : n;

	for (const int n : x)
		cout << n << " ";
	cout << endl;
}

int main()
{

	GradeProcess();

	return 0;
}