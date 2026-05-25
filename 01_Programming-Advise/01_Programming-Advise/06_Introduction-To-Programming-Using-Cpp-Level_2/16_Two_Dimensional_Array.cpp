// Two Dimensional Array
// Syntax : DataType VariableName [Row] [Colum]
// To avoid cash miss you should take data row by row (not colum by colum)


#include <iostream>
using namespace std;

void HowToUse()
{
	int x[3][4] = { {1,2,3,4},{5,6,7,8}, {9,10,11,12} };

	// [0][0] [0][1] [0][2]
	// [1][0] [1][1] [1][2]
	// [2][0] [2][1] [2][2]

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 3; j++)
			cout << x[i][j] << " ";

		cout << endl;
	}

}


int main()
{
	


	return 0;
}