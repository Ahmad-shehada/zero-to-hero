//Validate Number
//to solve cin stop working if enter a string or char insted a number


#include <iostream>
#include <limits>
using namespace std;

int ReadNumber()
{
	int Number = 0;
	string Message = "Please enter a Number : ";

	do
	{
		cout << Message;
		cin >> Number;

		if (cin.fail())//in case the user entered a char insted of Number cin.fail() will return true
		{
			cin.clear();//to clear fail flag and can use cin method again
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//to flush all data in input buffer until \n is reached to make empty input buffer
			Message = "Invalid Input Please enter a again : ";
		}
		else
			return Number;

	} while (true);
}


int main()
{

	cout << ReadNumber() << endl;
	//to see more example go to MyInput.h

	return 0;
}