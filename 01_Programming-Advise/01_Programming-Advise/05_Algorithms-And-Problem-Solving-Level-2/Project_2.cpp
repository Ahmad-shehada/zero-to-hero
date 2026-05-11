#include <iostream>
#include "MyInput.h"
#include "MyRandom.h"
using namespace std;

enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, Mix = 5};
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4};

struct stSetting
{
	short noOfQuestions = 0;
	enQuestionLevel QuestionsLevel = enQuestionLevel::Easy;
	enOperationType OperationType = enOperationType::Add;
};
struct stScore
{
	short noOfRightAnswers = 0;
	short noOfWrongAnswers = 0;
};
struct stQuestion
{
	short RoundNumber = 0;
	short FirstNumber = 0;
	short SecondNumber = 0;
	enOperationType OperationType = enOperationType::Add;
	enQuestionLevel QuestionLevel = enQuestionLevel::Easy;
	short UserAnswer = 0;
	short RightAnswer = 0;
	bool isCorrect = false;
};
struct stQuizz
{
	stSetting Setting;
	stQuestion QuestionsList[10];
	stScore Score;
	bool isPass = false;
};

//Screen
void ResetScreen()
{
	system("color 0F");
	system("cls");
}
void SetCorrectScreenColor(bool State)
{
	if (State)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

//Char method
char GetOperationChar(enOperationType OperationType)
{
	char charOperationType[4] = { '+', '-', '*', '/' };
	return charOperationType[OperationType - 1];
}
string GetLevelText(enQuestionLevel Level)
{
	string strLevel[4] = { "Easy", "Med", "Hard", "Mix" };
	return strLevel[Level - 1];
}
string GetOperationText(enOperationType OperationType)
{
	string strOperationType[5] = { "Add", "Sub", "Mult", "Div", "Mix" };
	return strOperationType[OperationType - 1];
}

//Fill stQuestion
bool isCorrect(short UserAnswer, short RigthAnswer)
{
	return UserAnswer == RigthAnswer;
}
short SimpleCalculate(short FirstNumber, short SecondNumber, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return FirstNumber + SecondNumber;

	case enOperationType::Sub:
		return FirstNumber - SecondNumber;

	case enOperationType::Mult:
		return FirstNumber * SecondNumber;

	case enOperationType::Div:
		return FirstNumber / SecondNumber;

	default:
		return -1;
	}
}
short GetNumber(enQuestionLevel Level)
{
	switch (Level)
	{
	case enQuestionLevel::Easy:
		return random::RandomNumber(1, 10);
		
	case enQuestionLevel::Med:
		return random::RandomNumber(10, 50);

	case enQuestionLevel::Hard:
		return random::RandomNumber(50, 100);

	default:
		return -1;
	}
}
enOperationType GetOperationType(enOperationType OperationType)
{
	if (OperationType != enOperationType::Mix)
		return OperationType;
	else
		return (enOperationType)random::RandomNumber(1, 4);
}
enQuestionLevel GetLevel(enQuestionLevel Level)
{
	if (Level != enQuestionLevel::MixLevel)
		return Level;
	else
		return (enQuestionLevel)random::RandomNumber(1, 3);
}
void GenerationQuestions(stQuestion QuestionsList[], const stSetting& Setting)
{
	for (int Question = 0; Question < Setting.noOfQuestions; Question++)
	{
		QuestionsList[Question].RoundNumber = Question + 1;
		QuestionsList[Question].QuestionLevel = GetLevel(Setting.QuestionsLevel);
		QuestionsList[Question].OperationType = GetOperationType(Setting.OperationType);
		QuestionsList[Question].FirstNumber = GetNumber(QuestionsList[Question].QuestionLevel);
		QuestionsList[Question].SecondNumber = GetNumber(QuestionsList[Question].QuestionLevel);
		QuestionsList[Question].RightAnswer = SimpleCalculate(QuestionsList[Question].FirstNumber, QuestionsList[Question].SecondNumber, QuestionsList[Question].OperationType);
	}
}

//Fill stQuizz
bool isPass(short noOfRightAnswer, short noOfWrongAnswers)
{
	return noOfRightAnswer >= noOfWrongAnswers;
}
stScore CalculateGameScore(stQuestion QuestionsList[], const stSetting& Setting)
{
	stScore Score;

	for (int Question = 0; Question < Setting.noOfQuestions; Question++)
	{
		if (QuestionsList[Question].isCorrect)
			Score.noOfRightAnswers++;
		else
			Score.noOfWrongAnswers++;
	}

	return Score;
}

//Fill stQuizzSetting
stSetting ReadQuizzSettings()
{
	stSetting Setting;

	Setting.noOfQuestions = in::ReadIntNumberInRange(1, 10, "How many questions do you want to answer 1 to 10 : ");
	Setting.QuestionsLevel = (enQuestionLevel)in::ReadIntNumberInRange(1, 4, "Enter Questions Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix : ", "Its not a Choice, Please enter Again : ");
	Setting.OperationType = (enOperationType)in::ReadIntNumberInRange(1, 5, "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mult, [4]:Div, [5]:Mix : ", "Its not a Choice, Please enter a again : ");

	return Setting;
}

//Rounds
void ShowQuestionResult(const stQuestion& Question)
{
	if (Question.isCorrect)
		cout << "Right Answer :)\n\n";
	else
	{
		cout << "Wrong Answer :(\n";
		cout << "The Right Answer is " << Question.RightAnswer << "\n\n";
	}
}
void ShowQuestion(const stQuestion& Question, short noOfQuestions)
{
	cout << "\nQuestion [" << Question.RoundNumber << "/" << noOfQuestions << "]\n";
	cout << "Level : " << GetLevelText(Question.QuestionLevel) << "\n\n";
	cout << Question.FirstNumber << "\n";
	cout << Question.SecondNumber << " " << GetOperationChar(Question.OperationType) << "\n";
	cout << "_____________________\n";
}
void AskAndCorrectQuestions(stQuestion QuestionsList[], short noOfQuestions)
{
	for (short Question = 0; Question < noOfQuestions; Question++)
	{
		ShowQuestion(QuestionsList[Question], noOfQuestions);
		QuestionsList[Question].UserAnswer = in::ReadInt("");
		QuestionsList[Question].isCorrect = isCorrect(QuestionsList[Question].UserAnswer, QuestionsList[Question].RightAnswer);
		ShowQuestionResult(QuestionsList[Question]);
	}
}
stQuizz PlayGame()
{
	stQuizz Quizz;

	Quizz.Setting = ReadQuizzSettings();
	GenerationQuestions(Quizz.QuestionsList, Quizz.Setting);
	AskAndCorrectQuestions(Quizz.QuestionsList, Quizz.Setting.noOfQuestions);
	CalculateGameScore(Quizz.QuestionsList, Quizz.Setting);
	Quizz.isPass = isPass(Quizz.Score.noOfRightAnswers, Quizz.Score.noOfWrongAnswers);

	return Quizz;
}

//Start And End Game
void ShowGameOver(bool isPass)
{
	cout << "\n__________________________________\n\n";
	cout << "    Final Result is ";

	if (isPass)
		cout << "Pass :)";
	else
		cout << "Fail :(";
	
	cout << "\n__________________________________\n\n";

	SetCorrectScreenColor(isPass);
}
void ShowQuizzResult(const stQuizz& Quizz)
{
	ShowGameOver(Quizz.isPass);
	cout << "\nNumber of Questions: " << Quizz.Setting.noOfQuestions << "\n";
	cout << "Questions Level    : " << GetLevelText(Quizz.Setting.QuestionsLevel) << "\n";
	cout << "OpType             : " << GetOperationText(Quizz.Setting.OperationType) << "\n";
	cout << "Number of Right Questions : " << Quizz.Score.noOfRightAnswers << "\n";
	cout << "Number of Wrong Questions : " << Quizz.Score.noOfWrongAnswers << "\n";
	cout << "__________________________________\n\n";
}
void StartGame()
{
	char PlayAgain = 'Y';
	stQuizz Quizz;

	do
	{
		ResetScreen();

		Quizz = PlayGame();
		ShowQuizzResult(Quizz);

		PlayAgain = in::ReadChar("Do you want to play again Y/N : ");

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	StartGame();

	return 0;
}