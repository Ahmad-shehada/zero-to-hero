#include <iostream>
#include <cstdlib>
using namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3};

struct stGameResult
{
	short GameRounds;
	short Player1WonTimes;
	short ComputerWonTimes;
	short DrawTimes;
	enWinner FinalWinner;
	string FinalWinnerName = "";
};
struct stRoundInfo
{
	short GameRound = 0;
	enChoice Player1Choice;
	enChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";
};


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enChoice ReadPlayerChoice()
{
	short PlayerChoice;

	cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?  ";
	cin >> PlayerChoice;

	return enChoice(PlayerChoice);
}
enChoice GetComputerChoice()
{
	return enChoice(RandomNumber(1, 3));
}

enWinner WhoWinnerRound(enChoice Player1Choice, enChoice ComputerChoice)
{
	if (Player1Choice == ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (Player1Choice)
	{
	case enChoice::Stone:
		if (ComputerChoice == enChoice::Paper)
			return enWinner::Computer;

		break;

	case enChoice::Paper:
		if (ComputerChoice == enChoice::Scissors)
			return enWinner::Computer;

		break;

	case enChoice::Scissors:
		if (ComputerChoice == enChoice::Stone)
			return enWinner::Computer;

		break;
	}

	//if reach here then the player 1 is won
	return enWinner::Player1;
}
string WinnerName(enWinner Winner)
{
	string WinnerName[3] = {"Player1", "Computer", "No Winner"};

	return WinnerName[Winner - 1];
}

void SetScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	case enWinner::Draw:
		system("color 6F");
		break;
	}
}

string ChoiceName(enChoice Choice)
{
	string ChoiceName[3] = { "Stone", "Paper", "Scissors"};

	return ChoiceName[Choice - 1];
}

void PrintRoundInfo(stRoundInfo RoundInfo)
{
	cout << "\n_____________________Round [" << RoundInfo.GameRound << "]_____________________\n";
	cout << "\nPlayer 1 Choice: " << ChoiceName(RoundInfo.Player1Choice);
	cout << "\nComputer Choice: " << ChoiceName(RoundInfo.ComputerChoice);
	cout << "\nRound Winner   : [" << RoundInfo.WinnerName << "]";
	cout << "\n___________________________________________________\n\n";

	SetScreenColor(RoundInfo.Winner);
}

enWinner FinalWinner(short Player1WonTimes, short ComputerWonTimes)
{
	if (Player1WonTimes > ComputerWonTimes)
		return enWinner::Player1;
	else if (Player1WonTimes < ComputerWonTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResult FillGameResultData(short NumberOfRound, short Player1WonTimes, short ComputerWonTimes, short DrawTimes)
{
	stGameResult GameResult;

	GameResult.GameRounds = NumberOfRound;
	GameResult.Player1WonTimes = Player1WonTimes;
	GameResult.ComputerWonTimes = ComputerWonTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.FinalWinner = FinalWinner(Player1WonTimes, ComputerWonTimes);
	GameResult.FinalWinnerName = WinnerName(GameResult.FinalWinner);

	return GameResult;
}

stGameResult PlayGame(int NumberOfRound)
{
	stRoundInfo RoundInfo;
	short Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= NumberOfRound; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] Begins :\n";
		RoundInfo.GameRound = GameRound;
		RoundInfo.Player1Choice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWinnerRound(RoundInfo.Player1Choice, RoundInfo.ComputerChoice);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		
		switch (RoundInfo.Winner)
		{
		case enWinner::Player1:
			Player1WonTimes++;
			break;

		case enWinner::Computer:
			ComputerWonTimes++;
			break;

		case enWinner::Draw:
			DrawTimes++;
			break;
		}

		PrintRoundInfo(RoundInfo);
	}


	return FillGameResultData(NumberOfRound, Player1WonTimes, ComputerWonTimes, DrawTimes);
}


string Taps(short NumberOfTaps)
{
	string Tap = "";

	for (int i = 1; i <= NumberOfTaps; i++)
	{
		Tap += "\t";
	}

	return Tap;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

short ReadHowManyRounds()
{
	short Rounds = 0;

	do
	{
		cout << "How Many Rounds 1 To 10 : ";
		cin >> Rounds;

	} while (Rounds < 1 || Rounds > 10);

	return Rounds;
}

void ShowGameOverScreen()
{
	cout << Taps(2) << "      _____________________________________________\n\n";
	cout << Taps(2) << "                  +++ G A M E  O V E R +++\n";
	cout << Taps(2) << "      _____________________________________________\n\n";
}
void ShowFinalGameResults(stGameResult GameResult)
{
	cout << Taps(2) << "_____________________ [ Game Results ] _____________________\n";
	cout << Taps(2) << "Game Rounds        : " << GameResult.GameRounds << "\n";
	cout << Taps(2) << "Player 1 won times : " << GameResult.Player1WonTimes << "\n";
	cout << Taps(2) << "Computer won times : " << GameResult.ComputerWonTimes << "\n";
	cout << Taps(2) << "Draw times         : " << GameResult.DrawTimes << "\n";
	cout << Taps(2) << "Final winner       : " << GameResult.FinalWinnerName << "\n";
}

void StartGame()
{
	char PlayAgain = 'Y';
	stGameResult GameResult;

	do
	{
		ResetScreen();
		GameResult = PlayGame(ReadHowManyRounds());

		ShowGameOverScreen();
		ShowFinalGameResults(GameResult);

		cout << "\n" << Taps(2) << "Do you want play again Y/N : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
	

	return 0;
}