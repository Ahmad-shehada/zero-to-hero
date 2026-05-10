#include <iostream>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player_1 = 1, Player_2 = 2, Draw = 3};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player_1 = enGameChoice::Stone;
	enGameChoice Player_2 = enGameChoice::Stone;
	enWinner Winner = enWinner::Draw;
};
struct stGameResult
{
	short noOfRound = 0;
	short Player1WonTimes = 0;
	short Player2WonTimes = 0;
	short DrawTimes = 0;
	enWinner FinalWinner = enWinner::Draw;
};

string Taps(short Num)
{
	string Taps = "";

	for (int i = 1; i <= Num; i++)
		Taps += "\t";

	return Taps;
}

//Screen
void ResetScreen()
{
	system("color 0F");
	system("cls");
}
void ScreenWin(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player_1:
		system("color 2F");
		break;

	case enWinner::Player_2:
		system("color 4F");
		cout << "\a";
		break;

	case enWinner::Draw:
		system("color 6F");
		break;
	}

}

//to_string method
string to_stringChoice(enGameChoice Choice)
{
	string strChoice[3] = { "Stone", "Paper", "Scissors" };
	return strChoice[Choice - 1];
}
string to_stringWinner(enWinner Winner)
{
	string strWinner[3] = { "Player_1", "Player_2", "Draw" };
	return strWinner[Winner - 1];
}

//fill stGameRound Data
enWinner RoundWinner(enGameChoice Player_1, enGameChoice Player_2)
{
	if (Player_1 == Player_2)
		return enWinner::Draw;

	switch (Player_1)
	{
	case enGameChoice::Stone:
		return (Player_2 == enGameChoice::Scissors)? enWinner::Player_1 : enWinner::Player_2;
	case enGameChoice::Paper:
		return (Player_2 == enGameChoice::Stone) ? enWinner::Player_1 : enWinner::Player_2;
	case enGameChoice::Scissors:
		return (Player_2 == enGameChoice::Paper) ? enWinner::Player_1 : enWinner::Player_2;
	}
}
enGameChoice PlayerChoice()
{
	return (enGameChoice)in::ReadIntNumberInRange(1, 3, "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors : ", "Its not a Choice Please try Again : ");
}
enGameChoice Player2Choice(bool isPlayer)
{
	if (isPlayer)
		return PlayerChoice();
	else
		return (enGameChoice)random::RandomNumber(1, 3);
}
stRoundInfo FillRoundInfo(short Round, bool isPlayer)
{
	stRoundInfo RoundInfo;

	RoundInfo.RoundNumber = Round;
	RoundInfo.Player_1 = PlayerChoice();
	RoundInfo.Player_2 = Player2Choice(isPlayer);
	RoundInfo.Winner = RoundWinner(RoundInfo.Player_1, RoundInfo.Player_2);

	return RoundInfo;
}

//fill stGameResult Data
enWinner FinalWinner(short Player1WonTimes, short Player2WonTime)
{
	if (Player1WonTimes > Player2WonTime)
		return enWinner::Player_1;
	else if (Player1WonTimes < Player2WonTime)
		return enWinner::Player_2;
	else
		return enWinner::Draw;
}
stGameResult FillGameResult(short Player1WonTimes, short Player2WonTimes, short DrawTimes, short noOfRound)
{
	stGameResult GameResult;

	GameResult.noOfRound = noOfRound;
	GameResult.Player1WonTimes = Player1WonTimes;
	GameResult.Player2WonTimes = Player2WonTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.FinalWinner = FinalWinner(GameResult.Player1WonTimes, GameResult.Player2WonTimes);

	return GameResult;
}

// Rounds
void PrintRoundResult(stRoundInfo& RoundInfo)
{
	cout << "\n______________ Round [" << RoundInfo.RoundNumber << "] ______________\n\n";
	cout << "Player 1 Choice : " << to_stringChoice(RoundInfo.Player_1) << "\n";
	cout << "Player 2 Choice : " << to_stringChoice(RoundInfo.Player_2) << "\n";
	cout << "Round Winner    : [" << to_stringWinner(RoundInfo.Winner) << "]\n";
	cout << "______________________________________\n";
	ScreenWin(RoundInfo.Winner);
}
stRoundInfo PlayRound(short Round, bool isPlayer)
{
	stRoundInfo RoundInfo;

	cout << "\nRound [" << Round << "] begins :\n\n";
	RoundInfo = FillRoundInfo(Round, isPlayer);
	PrintRoundResult(RoundInfo);

	return RoundInfo;
}
stGameResult PlayGame()
{
	stRoundInfo RoundInfo;
	short noOfRound = in::ReadIntNumberInRange(1, 10, "How Many Round 1 To 10 : ");
	bool isPlayer = in::ReadBoolean("Choose Opponent [1]:Another Player, [0]: Computer : ");
	short Player1WonTimes = 0, Player2WonTimes = 0, DrawTimes = 0;

	for (int Round = 1; Round <= noOfRound; Round++)
	{
		RoundInfo = PlayRound(Round, isPlayer);

		if (RoundInfo.Winner == enWinner::Player_1)
			Player1WonTimes++;
		else if (RoundInfo.Winner == enWinner::Player_2)
			Player2WonTimes++;
		else
			DrawTimes++;
	}

	return FillGameResult(Player1WonTimes, Player2WonTimes, DrawTimes, noOfRound);
}

//The Start And End Game
void PrintGameResult(stGameResult& GameResult)
{
	cout << Taps(2) << "__________________________________________________________\n";
	cout << Taps(4) << "+++  Game Over  +++\n";
	cout << Taps(2) << "__________________________________________________________\n";
	cout << Taps(2) << "____________________ [ Game Results ] ____________________\n";
	cout << Taps(2) << "Game Rounds          : " << GameResult.noOfRound << "\n";
	cout << Taps(2) << "Player 1 won times   : " << GameResult.Player1WonTimes << "\n";
	cout << Taps(2) << "Player 2 won times   : " << GameResult.Player2WonTimes << "\n";
	cout << Taps(2) << "Draw times           : " << GameResult.DrawTimes << "\n";
	cout << Taps(2) << "Final Winner         : [" << to_stringWinner(GameResult.FinalWinner) << "]\n";
	cout << Taps(2) << "__________________________________________________________\n";
	ScreenWin(GameResult.FinalWinner);
}
void StartGame()
{
	char PlayAgain = 'Y';
	stGameResult GameResult;

	do
	{
		ResetScreen();

		GameResult = PlayGame();
		PrintGameResult(GameResult);

		PlayAgain = in::ReadChar("Do you want to play again (Y/N) : ");

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{

	StartGame();

	return 0;
}