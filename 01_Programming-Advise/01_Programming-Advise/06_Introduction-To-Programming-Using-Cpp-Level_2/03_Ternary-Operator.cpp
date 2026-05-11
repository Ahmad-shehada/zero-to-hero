//Ternary_Operator or (Short Hand If)
//Its a way to write if else statemnt in one line
//Its a greate way to make your code more readable
//Its a expriaition not statment like if else so its return value or call function
//It has a lower Priority so you need to focuse 

#include <iostream>
#include <cmath>
using namespace std;

void Problem()
{
	cout <<  (true ? "Ahmad" : 3.0) << endl;
	//because its only return one data type
}
void Advance(int x, int y)
{
	double x = (x > y) ? x / y * pow(2, 3) : sqrt(x) * x / y;
	//if x > y is true thin will jamp in the true section and doesn't look in the false section 
	//its name lazy Evaluation
	(true) ? Advance(4, 3) : HowCompilarRead(5, 4);// you can put void function but you need a same data type(void, void)
}
void HowCompilarRead(int x, int y)
{
	double a = (x > y) ? 5 : 3.0;
	//5 convert to 5.0 (converte to a biggest data until doesn't happen miss data)
	//excute x > y
	//if true take true section
	//else take false section

	double b = (x > y) ?
		(x == 1) ? x : y :
		(y == 1) ? y : x;
	//(y == 1) ? y : x excute like variable a
	//(x == 1) ? x : y excute like variable a
	//(x > y) ? value1 : value2 excute like varialbe a
	//Right To Left
	
}


//Problem Solving
char GetLetterMark(int Number)
{
	return (Number >= 90) ? 'A' :
		   (Number >= 80) ? 'B' :
		   (Number >= 70) ? 'C' : 'F';
}

int GetMax(int a, int b, int c)
{
	return (a > b) ?
		(a > c) ? a : c :
		(b > c) ? b : c;
}

string StateMachine(bool isEmergency, int Timer)
{
	return (isEmergency || Timer > 60) ? "Green" :
		(Timer >= 20) ? "Yellow" : "Red";
}

int Calcualate(int a, int b, char op)
{
	return (op == '+') ? a + b :
		(op == '-') ? a - b :
		(op == '*') ? a * b :
		(op == '/' && b != 0) ? a / b : 0;
}


int main()
{
	


	return 0;
}