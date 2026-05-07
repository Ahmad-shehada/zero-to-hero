#include <iostream>
#include <MtInput.h>
using namespace std;

enum enState { Pass = 1, Fail = 2 };


enState CheckPass(float Number)
{
	if (Number >= 50)
		return enState::Pass;
	else
		return enState::Fail;
}

int main()
{
	float Number = in::ReadFloat("Please enter your mark : ");
	enState State = CheckPass(Number);
	
	if (State == enState::Pass)
		cout << "Pass" << endl;
	else
		cout << "Fail" << endl;

}