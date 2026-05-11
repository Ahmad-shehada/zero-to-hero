#include <iostream>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player_1 = 1, Player_2 = 2, Draw = 3};

struct stSetting
{
	short noOfRound = 0;
	bool isPlayer = false;
};
struct stRound
{
	short RoundNumber = 0;
	enGameChoice Player_1 = enGameChoice::Stone;
	enGameChoice Player_2 = enGameChoice::Stone;
	enWinner Winner = enWinner::Draw;
};
struct stScore
{
	short Player1WonTimes = 0;
	short Player2WonTimes = 0;
	short DrawTimes = 0;
};
struct stGame
{
	stRound Round[10];
	stSetting Setting;
	stScore Score;
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
void SetWinnerScreenColor(enWinner Winner)
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
string GetChoiceText(enGameChoice Choice)
{
	string strChoice[3] = { "Stone", "Paper", "Scissors" };
	return strChoice[Choice - 1];
}
string GetWinnerText(enWinner Winner)
{
	string strWinner[3] = { "Player_1", "Player_2", "Draw" };
	return strWinner[Winner - 1];
}

//fill stRound
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

	default:
		cout << "Its not expected!\n";
		return enWinner::Draw;
	}
}
enGameChoice GetPlayerChoice()
{
	return (enGameChoice)in::ReadIntNumberInRange(1, 3, "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors : ", "Its not a Choice Please try Again : ");
}
enGameChoice GetPlayer2Choice(bool isPlayer)
{
	if (isPlayer)
		return GetPlayerChoice();
	else
		return (enGameChoice)random::RandomNumber(1, 3);
}

//fill stScore
stScore CalculateGameScore(stRound Round[], const stSetting& Setting)
{
	stScore Score;

	for (int RoundNumber = 0; RoundNumber < Setting.noOfRound; RoundNumber++)
	{
		switch (Round[RoundNumber].Winner)
		{
		case enWinner::Player_1:
			Score.Player1WonTimes++;
			break;

		case enWinner::Player_2:
			Score.Player2WonTimes++;
			break;

		case enWinner::Draw:
			Score.DrawTimes++;
			break;

		default:
			cout << "Its not expected!";
			break;
		}
	}

	return Score;
}

//fill stGameSetting
stSetting ReadGameSetting()
{
	stSetting Setting;

	Setting.noOfRound = in::ReadIntNumberInRange(1, 10, "How Many Round 1 To 10 : ");
	Setting.isPlayer = in::ReadBoolean("Choose Opponent [1]:Another Player, [0]: Computer : ");

	return Setting;
}

//fill stGame
enWinner FinalWinner(short Player1WonTimes, short Player2WonTime)
{
	if (Player1WonTimes == Player2WonTime)
		return enWinner::Draw;
	else
		return (Player1WonTimes > Player2WonTime) ? enWinner::Player_1 : enWinner::Player_2;
}

// Rounds
void ShowRoundResult(const stRound& Round)
{
	cout << "\n______________ Round [" << Round.RoundNumber << "] ______________\n\n";
	cout << "Player 1 Choice : " << GetChoiceText(Round.Player_1) << "\n";
	cout << "Player 2 Choice : " << GetChoiceText(Round.Player_2) << "\n";
	cout << "Round Winner    : [" << GetWinnerText(Round.Winner) << "]\n";
	cout << "______________________________________\n";
}
stRound PlayRound(const stSetting& Setting, short RoundNumber)
{
	stRound Round;

	Round.RoundNumber = RoundNumber + 1;
	Round.Player_1 = GetPlayerChoice();
	Round.Player_2 = GetPlayer2Choice(Setting.isPlayer);

	return Round;
}
void RoundsBegin(stRound Round[], const stSetting& Setting)
{
	for (int RoundNumber = 0; RoundNumber < Setting.noOfRound; RoundNumber++)
	{
		cout << "\nRound [" << RoundNumber + 1 << "] begins :\n\n";
		Round[RoundNumber] = PlayRound(Setting, RoundNumber);
		Round[RoundNumber].Winner = RoundWinner(Round[RoundNumber].Player_1, Round[RoundNumber].Player_2);
		ShowRoundResult(Round[RoundNumber]);
	}
}

//Start And End Game
stGame PlayGame()
{
	stGame Game;

	Game.Setting = ReadGameSetting();
	RoundsBegin(Game.Round, Game.Setting);
	Game.Score = CalculateGameScore(Game.Round, Game.Setting);
	Game.FinalWinner = FinalWinner(Game.Score.Player1WonTimes, Game.Score.Player2WonTimes);

	return Game;
}
void ShowGameOverScreen()
{
	cout << Taps(2) << "__________________________________________________________\n";
	cout << Taps(2) << "                  +++  Game Over  +++\n";
	cout << Taps(2) << "__________________________________________________________\n";
}
void ShowGameResult(const stGame& Game)
{
	ShowGameOverScreen();
	cout << Taps(2) << "____________________ [ Game Results ] ____________________\n";
	cout << Taps(2) << "Game Rounds          : " << Game.Setting.noOfRound << "\n";
	cout << Taps(2) << "Player 1 won times   : " << Game.Score.Player1WonTimes << "\n";
	cout << Taps(2) << "Player 2 won times   : " << Game.Score.Player2WonTimes << "\n";
	cout << Taps(2) << "Draw times           : " << Game.Score.DrawTimes << "\n";
	cout << Taps(2) << "Final Winner         : [" << GetWinnerText(Game.FinalWinner) << "]\n";
	cout << Taps(2) << "__________________________________________________________\n";
	SetWinnerScreenColor(Game.FinalWinner);
}
void StartGame()
{
	char PlayAgain = 'Y';
	stGame GameResult;

	do
	{
		ResetScreen();

		GameResult = PlayGame();
		ShowGameResult(GameResult);

		PlayAgain = in::ReadChar("Do you want to play again (Y/N) : ");

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{

	StartGame();

	return 0;
}