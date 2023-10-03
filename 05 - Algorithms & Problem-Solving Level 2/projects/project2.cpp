#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <iomanip>
using namespace std;

enum enQuestionLevel
{
    Easy = 1,
    Med,
    Hard,
    Mix
};
string ArrLevel[5] = {"", "Easy", "Med", "Hard", "Mix"};

enum enOperatorType
{
    Add = 1,
    Sub,
    Mul,
    Div,
    MixType
};
string ArrOperatorType[6] = {"", "Add", "Sub", "Mul", "Div", "Mix"};
char ArrOperatorCharacter[5] = {' ', '+', '-', '*', '/'};

enum enFinalResult
{
    Fail,
    Pass
};
string ArrFinalResult[] = {"Fail", "Pass"};
/*
 0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White
*/
enum EnGameBackColor
{
    Right = 2,
    wrong = 4,
    Res = 0
};

short ReadPositiveNumber(string UserText);

float ReadNumberInRange(string UserText, const int Max, const int Min);

int GetRandomNumber(int From, int To);
char ReadCharacter(string UserText);
void changeColor(EnGameBackColor BackColor);

struct stGameResult
{
    int NumberOfQuestion;
    string QuestionLevel;
    string OperationType;
    short NumberOfRightAnswers;
    short NumberOfWrongAnswers;
    string FinalResult;

    void setGameResultValues(int NumberOfQuestions, enQuestionLevel QuestionLevel, enOperatorType OperationType, short NumberOfRightAn, short NumberOfWrongAn)
    {
        this->NumberOfQuestion = NumberOfQuestions;
        this->QuestionLevel = ArrLevel[QuestionLevel];
        this->OperationType = ArrOperatorType[OperationType];
        this->NumberOfRightAnswers = NumberOfRightAn;
        this->NumberOfWrongAnswers = NumberOfWrongAn;
    }
    void SetFinalResult()
    {

        NumberOfRightAnswers >= NumberOfWrongAnswers ? this->FinalResult = ArrFinalResult[enFinalResult::Pass] : this->FinalResult = ArrFinalResult[enFinalResult::Fail];
    }

    void PrintResult()
    {
        cout << "\n__________________________________________________________\n";
        if (FinalResult == "Pass")
        {
            changeColor(EnGameBackColor::Right);
            cout << "Final Result is " << this->FinalResult << "-)\n";
        }
        else
        {
            changeColor(EnGameBackColor::wrong);
            cout << "Final Result is " << this->FinalResult << "-(\n";
        }

        cout << "\n__________________________________________________________\n";
        cout << "Question Level            :" << QuestionLevel << "\n";
        cout << "OpType                    :" << OperationType << "\n";
        cout << "Number Of Right  Answers  :" << NumberOfRightAnswers << "\n";
        cout << "Number Of Wrong Answers   :" << NumberOfWrongAnswers << "\n";
        cout << "\n__________________________________________________________\n";
    }
};
struct stQuestion
{

    float Operand1;
    char Operator;
    float Operand2;
    float Result;

    float GetResult(float Operand1, enOperatorType Operator, float Operand2)
    {

        switch (Operator)
        {
        case enOperatorType::Add:
            return Operand1 + Operand2;
        case enOperatorType::Sub:
            return Operand1 - Operand2;
        case enOperatorType::Mul:
            return Operand1 * Operand2;
        case enOperatorType::Div:
            return Operand1 / Operand2;
        case enOperatorType::MixType:
            short OperatorOperation = GetRandomNumber(1, 4);
            this->Operator = ArrOperatorCharacter[OperatorOperation];
            return GetResult(Operand1, enOperatorType(OperatorOperation), Operand2);
        }
    }
    void setValues(float Operand1, enOperatorType Operator, float Operand2)
    {
        this->Operand1 = Operand1;
        if (Operator != enOperatorType::MixType)
            this->Operator = ArrOperatorCharacter[Operator];
        this->Operand2 = Operand2;
        this->Result = GetResult(Operand1, Operator, Operand2);
    }
    void PrintQuestion(short QuestionIndex, short NumberOfQuestions)
    {

        cout << "Questions  [" << QuestionIndex << "/" << NumberOfQuestions << "] \n\n";
        cout << this->Operand1 << "\n";
        cout << this->Operand2 << " " << Operator << "\n";
        cout << "______________________\n";
    }
    void CheckIfUserAnswerIsRight(float UserAnswer, stGameResult &GameResult)
    {

        float FirstUserFloatDigit = (UserAnswer * 10);
        FirstUserFloatDigit = int(FirstUserFloatDigit) % 10;

        float FirstResultFloatDigit = (this->Result * 10);
        FirstResultFloatDigit = int(FirstResultFloatDigit) % 10;

        if ((this->Operator == '/' && FirstResultFloatDigit == FirstUserFloatDigit) || (this->Operator != '/' && UserAnswer == this->Result))
        {

            cout << "Right Answer :-)\n";
            changeColor(EnGameBackColor::Right);
            GameResult.NumberOfRightAnswers++;
        }
        else
        {
            cout << "Wrong Answer :-)\n";
            cout << "The Right Answer is : " << Result << "\n";
            changeColor(EnGameBackColor::wrong);
            GameResult.NumberOfWrongAnswers++;
        }
    }
};

enQuestionLevel GetQuestionsLevel()
{
    short Level = 0;
    do
    {

        cout << "Enter Questions Level [1] Easy ,[2] Med , [3] Hard , [4] Mix ? ";
        cin >> Level;
        cin.ignore();
        if (cin.fail())
            throw runtime_error("Invalid Questions Level : ");

    } while (Level < enQuestionLevel::Easy || Level > enQuestionLevel::Mix);

    return enQuestionLevel(Level);
}
enOperatorType GetOperandType()
{
    short OperandType = 0;
    do
    {

        cout << "Enter Questions Type [1] Add ,[2] Sub , [3] MUl , [4] Div , [5] Mix  ? ";
        cin >> OperandType;
        cin.ignore();
        if (cin.fail())
            throw runtime_error("Invalid Questions Type : ");

    } while (OperandType < enOperatorType::Add || OperandType > enOperatorType::MixType);

    return enOperatorType(OperandType);
}

short GetRandomNumberDependOnLevel(enQuestionLevel Level)
{

    switch (Level)
    {
    case enQuestionLevel::Easy:
        return GetRandomNumber(0, 9);
    case enQuestionLevel::Med:
        return GetRandomNumber(0, 30);
    case enQuestionLevel::Hard:
        return GetRandomNumber(30, 250);
    case enQuestionLevel::Mix:
        return GetRandomNumberDependOnLevel(enQuestionLevel(GetRandomNumber(1, 4)));
    }
}
stQuestion GetQuestion(enQuestionLevel Level, enOperatorType Type)
{

    stQuestion Question;
    short op1 = GetRandomNumberDependOnLevel(Level);
    short op2 = GetRandomNumberDependOnLevel(Level);
    Question.setValues(op1, Type, op2);
    return Question;
}
void ManageQuestion(stQuestion &Question, stGameResult &GameResult, enQuestionLevel QuestionLevel, enOperatorType OperandType, short CurrentIndex, short NumberOfQuestions)
{
    Question = GetQuestion(QuestionLevel, OperandType);
    Question.PrintQuestion(CurrentIndex, NumberOfQuestions);
    float UserAnswer = ReadNumberInRange("", -62500, 62500);
    _sleep(45);
    Question.CheckIfUserAnswerIsRight(UserAnswer, GameResult);
}
stGameResult GetGameResult(short NumberOfQuestions)
{
    stQuestion Question;
    stGameResult GameResult;
    enQuestionLevel QuestionsLevel = GetQuestionsLevel();
    enOperatorType OperandType = GetOperandType();
    GameResult.setGameResultValues(NumberOfQuestions, QuestionsLevel, OperandType, 0, 0);

    for (short i = 0; i < NumberOfQuestions; i++)
    {
        ManageQuestion(Question, GameResult, QuestionsLevel, OperandType, i, NumberOfQuestions);
    }

    GameResult.SetFinalResult();

    return GameResult;
}

int GetStart()
{
    stGameResult GameResult;
    short NumberOfQuestions = 0;
    short WannaRepeatGame = 'n';
    do
    {
        system("cls");
        changeColor(EnGameBackColor::Res);
        NumberOfQuestions = ReadNumberInRange("How many Questions do want To answer : ? ", 0, 40000);
        GameResult = GetGameResult(NumberOfQuestions);
        _sleep(45);
        GameResult.PrintResult();
        WannaRepeatGame = toupper(ReadCharacter("Do you Want to play Again y/N ? "));

    } while (WannaRepeatGame == 'Y');

    changeColor(EnGameBackColor::Res);
    cout << "God By We will miss you : ";
    system("pause");
}
int main()
{
    srand(time(NULL));
    cout << fixed << setprecision(1) << endl;

    try
    {
        GetStart();
    }
    catch (runtime_error e)
    {
        cin.clear();
        changeColor(EnGameBackColor::Res);
        cerr << "Error " << e.what() << endl;
        system("pause");
    }

    return 0;
}

short ReadPositiveNumber(string UserText)
{
    short num = 0;

    do
    {
        cout << UserText;
        cin >> num;
    } while (num <= 0);
    return num;
}

float ReadNumberInRange(string UserText, const int Max, const int Min)
{
    float num = 0;
    do
    {
        cout << UserText;
        cin >> num;
        cin.ignore();
        if (cin.fail())
            throw runtime_error("Invalid  Value  you should enter A digit : ");

    } while (Max > num || Min < num);

    return num;
}
int GetRandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}
char ReadCharacter(string UserText)
{
    char Letter = ' ';
    cout << UserText;
    cin >> Letter;

    return Letter;
}
void changeColor(EnGameBackColor BackColor)
{

    string backSystemInstruction = "color " + to_string(BackColor) + "F";
    system(backSystemInstruction.data());
}