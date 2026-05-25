// Vectors
// It's a dynumic array can change size while run time
// Syntax : vector<T> vector_name
// It works like call stack in Add or Delete Element in lesson 11 


#include <iostream>
#include <vector>
using namespace std;

void DeclarationAndInitialization()
{
	vector<int> vNumbers = { 10, 20, 30, 40, 50 };

	for (const int& Number : vNumbers) // By Ref it's more performance in vector until with short
		cout << Number << " ";

	cout << endl;
}

void AddAndDeleteElement()
{
	vector<int> vNumbers;

	vNumbers.push_back(10); 
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);
	//vNumbers.push_back(60); // in here doesn't make reallocation becasue the capacity is 6 
	//vNumbers.push_back(70); // in here capacity = 9 so you can store 3 element without reallocation

	// Note : for call push_back method the vector will reallocate memory only when the capacity is full and this makse less performance so we use reserve(5) to make reallocation one time
	// capacity = ceil(capacity * 1.5) 

	for (const int& Number : vNumbers)
		cout << Number << " ";
	cout << endl;

	vNumbers.pop_back(); // pop(50)
	vNumbers.pop_back(); // pop(40)
	vNumbers.pop_back(); // pop(30)
	vNumbers.pop_back(); // pop(20)
	
	// Note : The pop method delete the element and moves 'back' backwards but it can't reallocation to the size after call pop

	for (const int& Number : vNumbers)
		cout << Number << " ";
	cout << endl;

	vNumbers.pop_back(); // pop(10)
	//vNumbers.pop_back(); // will throw error
}

struct stEmployees
{
	string FirstName = "";
	string LastName = "";
	int salary = 0;
};
void AddStructure()
{
	vector<stEmployees> vEmployees;
	stEmployees Temp;

	Temp.FirstName = "Ahmad";
	Temp.LastName = "Shehada";
	Temp.salary = 500;
	vEmployees.push_back(Temp);

	Temp.FirstName = "Ayman";
	Temp.LastName = "Awad";
	Temp.salary = 5000;
	vEmployees.push_back(Temp);

	Temp.FirstName = "Rasha";
	Temp.LastName = "Kilab";
	Temp.salary = 100;
	vEmployees.push_back(Temp);

	for (const stEmployees& Employee : vEmployees)
	{
		cout << "\nName : " << Employee.FirstName << " " << Employee.LastName << "\n";
		cout << "Salary : " << Employee.salary << "\n\n";
	}

}

void VectorFunctions()
{
	vector<int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);
	vNumbers.push_back(60);
	vNumbers.push_back(70);
	vNumbers.push_back(80);
	vNumbers.push_back(90);

	cout << vNumbers.front() << endl; // The first element of vector
	cout << vNumbers.back() << endl; // The last element of vector

	cout << vNumbers.size() << endl; // The number of element of vector
	cout << vNumbers.capacity() << endl; // The total allocated memory capacity of vector

	cout << vNumbers.empty() << endl; // Checks if the vector is empty or not
	vNumbers.clear(); // Delete all element in vector but can't reallocate of vector

	//vNumbers.front(); // will throw error
	//vNumbers.back(); // will throw error
}

void AccessElements()
{
	vector<int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	cout << vNumbers.at(0) << endl;
	cout << vNumbers.at(2) << endl;
	cout << vNumbers.at(4) << endl;

	cout << vNumbers[0] << endl;
	cout << vNumbers[2] << endl;
	cout << vNumbers[4] << endl;

// will throw error
	//cout << vNumbers.at(-1) << endl;
	//cout << vNumbers[-1] << endl;
	//cout << vNumbers.at(5) << endl;
	//cout << vNumbers[5] << endl;
}

void ChangeElements()
{
	vector<int> vNumbers = { 1, 2, 3, 4, 5 };

	vNumbers.at(2) = 10;
	vNumbers[0] = 4;

	for (const int& Number : vNumbers)
		cout << Number << " ";
	cout << endl;

	for (int& Number : vNumbers)
		Number = 20;

	for (const int& Number : vNumbers)
		cout << Number << " ";
	cout << endl;
}

int main()
{

	AccessElements();

	return 0;
}