#include <iostream>
#include "MyInput.h"
using namespace std;

string Encrypt(string Text, int EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] += EncryptionKey;
	}

	return Text;
}
string Decrypt(string Text, int EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] -= EncryptionKey;
	}

	return Text;
}


int main()
{
	int EncryptionKey = in::ReadPositiveIntNumber("Please enter a Key : ");

	string Text = in::ReadString("Please enter a Text : ");
	string EncryptText = Encrypt(Text, EncryptionKey);
	string DecryptText = Decrypt(EncryptText, EncryptionKey);

	cout << "\nThe Text Before Encrypt : " << Text << endl;
	cout << "The Text After Encrypt : " << EncryptText << endl;
	cout << "The Text After Decrypt : " << DecryptText << endl;

	return 0;
}