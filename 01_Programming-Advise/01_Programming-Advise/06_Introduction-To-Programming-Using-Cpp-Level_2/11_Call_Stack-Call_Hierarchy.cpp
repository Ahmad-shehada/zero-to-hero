// Call Stack Call Hierarchy
// Its a Data Structure in a ram and it has a limit

// Stack Frame : Its a data of the function like (Local variable, Parameters, Return Address)
// Push : To add Stack Frame to Call Stack
// Pop : To delete Stack Frame from Call Stack
// Active Fram : Its a cursor pointer to the function that cpu excute right now

// The Different of Call Stack and Call Hierarchy
// Call Hierarchy
// Its a static folder to see the all possible path of this function
// To see call stack click in right click and choice call hierarachy
// Calls To Function : This is a folder who call this function
// Calls From Function : This is a folder what this function call

// Call Stack
// Its a dynamic folder to see
// where the active frame
// See the push stack frame
// See the pop stack frame
// To see call stack you must be in running time and go to Debug->Windows->Call Stack

#include <iostream>
using namespace std;

// ______________How Cpu Read_______________

// Step 1
// 5 Function_4() push
// 4 Function_3() push
// 3 Function_2() push
// 2 Function_1() push
// 1 main() push

// Step 2
// 1 Function_4() pop
// 2 Function_3() pop
// 3 Function_2() pop
// 4 Function_1() pop
// 5 main() pop


void Function_4()
{
	cout << "Function 4\n";
}
void Function_3()
{
	cout << "Function 3\n";
	Function_4();
}
void Function_2()
{
	cout << "Function 2\n";
	Function_3();
}
void Function_1()
{
	cout << "Function 1\n";
	Function_2();
}

int main()
{
	Function_1();

	return 0;
}


