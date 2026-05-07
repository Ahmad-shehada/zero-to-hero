#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, OpMix = 5 };

struct stQuestion
{
	short Number_1 = 0;
	short Number_2 = 0;
	enQuestionLevel QuestionLevel = enQuestionLevel::Mix;
	enOperationType OpType = enOperationType::OpMix;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool AnswerResult = false;
};
struct stQuizz
{
	stQuestion QuestionList[10];
	short NumberOfQuestion = 0;
	enQuestionLevel QuestionLevel = enQuestionLevel::Mix;
	enOperationType OpType = enOperationType::OpMix;
	short NumberOfRightQuestions = 0;
	short NumberOfWrongQuestion = 0;
	bool isPass = false;
};


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

string GetLevelText(enQuestionLevel QuestionLevel)
{
	string QuestionLevelText[4] = {"Easy", "Med", "Hard", "Mix"};
	
	return QuestionLevelText[QuestionLevel - 1];
}
string GetOpTypeText(enOperationType OperationType)
{
	string OpTypeText[5] = { "+", "-", "*", "/", "Mix" };

	return OpTypeText[OperationType - 1];
}
void SetScreenColor(bool AnswerResult)
{
	if (AnswerResult)
		system("color 2F");
	else
		system("color 4F");
}

short ReadHowManyQuestion()
{
	short NumberOfQuestion = 0;

	do
	{
		cout << "How many Question do you want to answer 1 to 10 : ";
		cin >> NumberOfQuestion;

	} while (NumberOfQuestion < 1 || NumberOfQuestion > 10);

	return NumberOfQuestion;
}
enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;

	do
	{
		cout << "Enter Question Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix : ";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return enQuestionLevel(QuestionLevel);
}
enOperationType ReadOperationType()
{
	short OpType = 0;

	do
	{
		cout << "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mult, [4]:Div, [5]:Mix : ";
		cin >> OpType;

	} while (OpType < 1 || OpType > 5);

	return enOperationType(OpType);
}

short SimpleCaluclator(short Number_1, short Number_2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number_1 + Number_2;
		break;

	case enOperationType::Sub:
		return Number_1 - Number_2;
		break;

	case enOperationType::Mult:
		return Number_1 * Number_2;
		break;

	case enOperationType::Div:
		return Number_1 / Number_2;
		break;

	default:
		return -1;
		break;
	}
}
stQuestion GenerationQuestion(enQuestionLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = (enQuestionLevel) RandomNumber(1, 3);
	}
	if (OpType == enOperationType::OpMix)
	{
		OpType = (enOperationType)RandomNumber(1, 4);
	}

	Question.QuestionLevel = QuestionLevel;
	Question.OpType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		Question.Number_1 = RandomNumber(1, 10);
		Question.Number_2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCaluclator(Question.Number_1, Question.Number_2, Question.OpType);
		break;

	case enQuestionLevel::Med:
		Question.Number_1 = RandomNumber(10, 50);
		Question.Number_2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCaluclator(Question.Number_1, Question.Number_2, Question.OpType);
		break;

	case enQuestionLevel::Hard:
		Question.Number_1 = RandomNumber(50, 100);
		Question.Number_2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCaluclator(Question.Number_1, Question.Number_2, Question.OpType);
		break;
	}

	return Question;
}
void GenerationQuestionList(stQuizz& Quizz)
{
	for (int QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
	{
		Quizz.QuestionList[QuestionNumber] = GenerationQuestion(Quizz.QuestionLevel, Quizz.OpType);
	}
}

void PrintQuestion(stQuestion& Question, short QuestionNumber, short NumberOfQuestion)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << NumberOfQuestion << "]" << "\n";
	cout << "Level " << GetLevelText(Question.QuestionLevel) << "\n\n";
	cout << Question.Number_1 << "\n";
	cout << Question.Number_2 << " " << GetOpTypeText(Question.OpType) << "\n";
	cout << "_____________";
	cout << "\n";
}
short ReadPlayerAnswer()
{
	short PlayerAnswer = 0;

	cin >> PlayerAnswer;

	return PlayerAnswer;
}
void CorrectQuestionAnswer(stQuestion Question, short& NumberOfRightQuestion, short& NumberOfWrongQuestion)
{
	if (Question.CorrectAnswer == Question.PlayerAnswer)
	{
		NumberOfRightQuestion++;
		Question.AnswerResult = true;

		cout << "Right Answer :-)\n";
	}
	else
	{
		NumberOfWrongQuestion++;
		Question.AnswerResult = false;

		cout << "Wrong Answer :-(\n";
		cout << "The Right Answer is " << Question.CorrectAnswer << "\n";
	}

	SetScreenColor(Question.AnswerResult);
}
void AskAndCorrectQuestionListAnswer(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
	{
		PrintQuestion(Quizz.QuestionList[QuestionNumber], QuestionNumber, Quizz.NumberOfQuestion);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();
		CorrectQuestionAnswer(Quizz.QuestionList[QuestionNumber], Quizz.NumberOfRightQuestions, Quizz.NumberOfWrongQuestion);
	}

	Quizz.isPass = (Quizz.NumberOfRightQuestions >= Quizz.NumberOfWrongQuestion);
}

string GetIsPassText(bool isPass)
{
	if (isPass)
		return "Pass :-)";
	else
		return "Fail :-(";
}
void PrintFinalResult(stQuizz Quizz)
{	
	cout << "\n\n";
	cout << "________________________________________\n";
	cout << "  Final Results is " << GetIsPassText(Quizz.isPass) << "\n";
	cout << "________________________________________\n\n";
	cout << "Number Of Question : " << Quizz.NumberOfQuestion << "\n";
	cout << "Question Level     : " << GetLevelText(Quizz.QuestionLevel) << "\n";
	cout << "OpType             : " << GetOpTypeText(Quizz.OpType) << "\n";
	cout << "Number of Right Qestion  : " << Quizz.NumberOfRightQuestions << "\n";
	cout << "Number of Worng Question : " << Quizz.NumberOfWrongQuestion << "\n";
	cout << "________________________________________\n\n";

	SetScreenColor(Quizz.isPass);
}

void PlayGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestion = ReadHowManyQuestion();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OpType = ReadOperationType();

	GenerationQuestionList(Quizz);
	AskAndCorrectQuestionListAnswer(Quizz);
	PrintFinalResult(Quizz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	
	do
	{
		ResetScreen();
		PlayGame();

		cout << "Do you want play again ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}