#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <Limits>
using namespace std;

namespace in
{
	void ResetBuffer() //Make flush the buffer of any date can make Error!
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	double GetValidInput(const string& MessageError)//in case the user entered a character intested of number in data type (short int float double)
	{
		double Number = 0;

		while (true)
		{
			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				ResetBuffer();
				cout << MessageError;
			}
			else
			{
				ResetBuffer();//in case user entered like (123abc)
				return Number;
			}
		}

	}

	short ReadShort(const string& Message, const string& MessageError = "Invalid Input Please try again : ")
	{
		short Number = 0;

		cout << Message;
		Number = short(GetValidInput(MessageError));

		return Number;
	}
	int ReadInt(const string& Message, const string& MessageError = "Invalid Input Please try again : ")
	{
		int Number = 0;

		cout << Message;
		Number = int(GetValidInput(MessageError));

		return Number;
	}
	float ReadFloat(const string& Message, const string& MessageError = "Invalid Input Please try again : ")
	{
		float Number = 0.0f;

		cout << Message;
		Number = float(GetValidInput(MessageError));

		return Number;
	}
	double ReadDouble(const string& Message, const string& MessageError = "Invalid Input Please try again : ")
	{
		double Number = 0.0;

		cout << Message;
		Number = GetValidInput(MessageError);

		return Number;
	}

	char ReadChar(const string& Message)
	{
		char Character = 'A';

		cout << Message;
		cin >> Character;

		ResetBuffer();//in case user entered like (assass)

		return Character;
	}
	string ReadString(const string& Message)
	{
		string Text = "";

		cout << Message;
		getline(cin >> ws, Text);

		return Text;
	}
	bool ReadBoolean(const string& Message)
	{
		bool State = false;

		cout << Message;
		cin >> State;

		return State;
	}


	int ReadPositiveNumber(const string& Message)
	{
		int Number = 0;

		do
		{
			Number = ReadInt(Message);

		} while (Number < 0);

		return Number;
	}
	int ReadNegativeNumber(const string& Message)
	{
		int Number = 0;

		do
		{
			Number = ReadInt(Message);

		} while (Number > 0);

		return Number;
	}
	int ReadNumberInRange(int From, int To, const string& Message, const string& MessageError = "Invalid Input Please try again : ")
	{
		int Number = 0;

		do
		{
			Number = ReadInt(Message, MessageError);

		} while (Number < From || Number > To);

		return Number;
	}

}
