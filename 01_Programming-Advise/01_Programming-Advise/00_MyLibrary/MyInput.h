#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <Limits>
using namespace std;



namespace in
{
	namespace message
	{
		const string MessageError = "Error : Invalid Input Please try again : ";// For Invalid Input
		const string RangeMessageError = "Error : Out of Range Please try again : ";// For invalid selected range
	}

	void ResetBuffer() //flushing the input buffer of any date can make Error!
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
				cin.clear(); // to clear fail flage of cin
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

	short ReadShort(const string& Message, const string& MessageError = message::MessageError)
	{
		short Number = 0;

		cout << Message;
		Number = short(GetValidInput(MessageError));

		return Number;
	}
	int ReadInt(const string& Message, const string& MessageError = message::MessageError)
	{
		int Number = 0;

		cout << Message;
		Number = int(GetValidInput(MessageError));

		return Number;
	}
	float ReadFloat(const string& Message, const string& MessageError = message::MessageError)
	{
		float Number = 0.0f;

		cout << Message;
		Number = float(GetValidInput(MessageError));

		return Number;
	}
	double ReadDouble(const string& Message, const string& MessageError = message::MessageError)
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
		// it uses getline inseted of cin because the stopping condition of take data in the input buffer is only \n, unlike cin (\n, space, tab)
		// std::ws to ignore any (\n, white space, tabs) until the real data is reached
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


	int ReadPositiveNumber(const string& Message, const string& RangeMessageError = message::RangeMessageError, const string& MessageError = message::MessageError)
	{
		int Number = 0;
		string _Message = Message;

		do
		{
			Number = ReadInt(_Message, MessageError);

			if (Number > 0)
				break;

			_Message = RangeMessageError;

		} while (true);

		return Number;
	}
	int ReadNegativeNumber(const string& Message, const string& RangeMessageError = message::RangeMessageError, const string& MessageError = message::MessageError)
	{
		int Number = 0;
		string _Message = Message;

		do
		{
			Number = ReadInt(_Message, MessageError);

			if (Number < 0)
				break;

			_Message = RangeMessageError;

		} while (true);

		return Number;
	}
	int ReadNumberInRange(int From, int To, const string& Message, const string& RangeMessageError = message::RangeMessageError, const string& MessageError = message::MessageError)
	{
		int Number = 0;
		string _Message = Message;
		do
		{
			Number = ReadInt(_Message, MessageError);

			if (Number >= From && Number <= To)
				break;

			_Message = RangeMessageError;

		} while (true);

		return Number;
	}

}
