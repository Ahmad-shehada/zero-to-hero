//Declaration Vs Definition
//use to call function that the down of the current function

#include <iostream>
using namespace std;

void function_3();

void Problem()
{
	function_3();//happen linker error 
}


//that say the computer this function is exsist
void function_2(int, int);//Declaration 

void function_1()
{
	function_2(3, 5);
	cout << "I am function_1\n";
}
void function_2(int a, int b)//Definition
{
	cout << "I am function_2\n";
}


int main()
{
	function_1();

	return 0;
}
