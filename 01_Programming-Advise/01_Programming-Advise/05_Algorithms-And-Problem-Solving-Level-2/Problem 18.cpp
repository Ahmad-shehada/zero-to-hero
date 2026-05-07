#include <iostream>
#include <string>
using namespace std;


string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

string EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
		Text[i] = char(Text[i]) + EncryptionKey;

	return Text;
}
string DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
		Text[i] = char(Text[i]) - EncryptionKey;

	return Text;
}

void PrintResult(string Word)
{
	const short EncryptionKey = 2;

	cout << "\nThe Word is " << Word;
	cout << "\nThe Word After Encryprion " << EncryptText(Word, EncryptionKey);
	cout << "\nThe Word After Decryption " << DecryptText(EncryptText(Word, EncryptionKey), EncryptionKey) << "\n";
}


int main()
{
	PrintResult(ReadText("Please enter a Word : "));

	return 0;
}