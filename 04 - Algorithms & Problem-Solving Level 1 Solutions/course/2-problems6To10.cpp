#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// #6  get FirstName and LastName then Print the Full name on The Screen :

struct stFullName
{
    string FirstName;
    string LastName;
};

stFullName ReadUserInfo()
{
    stFullName FullName;

    cout << "Enter your Name :";
    getline(cin >> ws, FullName.FirstName);

    cout << "Enter your Last Name :";
    getline(cin >> ws, FullName.LastName);

    return FullName;
}

string GetFullName(stFullName FullName)
{

    return FullName.FirstName + " " + FullName.LastName;
}

void PrintFullName(string FullName)
{
    cout << "Your Full Name is : " << FullName << endl;
}

// #7  get a Number then print its half :
int GetNumber()
{
    int Number = 0;
    cout << "enter a Number :";
    cin >> Number;
    return Number;
}

float CalculateHalfOfNumber(int Number)
{
    return Number / 2.0;
}

void PrintHalfOfNumber(float halfOfNumber)
{
    cout << "the half is : " << fixed << setprecision(2) << halfOfNumber << endl;
}

// #8  get mark if mark>50 print pass else print fail :

enum enStudentStat
{
    Fail,
    Pass
};

float GetMark()
{
    float Mark = 0;
    cout << "Enter your Mark :";
    cin >> Mark;
    return Mark;
}
enStudentStat isAcceptedMark(float Mark)
{
    return Mark >= 50 ? enStudentStat::Pass : enStudentStat::Fail;
}
void PrintStudentResult(float Mark)
{
    isAcceptedMark(Mark) == enStudentStat::Pass ? cout << "Pass" : cout << "Fail";
}

// #9 sum of there Numbers :

void ReadNumbers(int Numbers[3])
{
    cout << "Enter There   Numbers :";
    for (int i = 0; i < 3; i++)
    {

        cin >> Numbers[i];
    }
}

int CalculateSumOfNumbers(int Numbers[3])
{
    int SumNumbers = 0;
    for (int i = 0; i < 3; i++)
    {
        SumNumbers += Numbers[i];
    }
    return SumNumbers;
}
void PrintSumOfThereNumbers(int Numbers[3])
{
    cout << "the Sum of Numbers are : " << CalculateSumOfNumbers(Numbers);
}

// # 10 average of there marks :
float CalculateAverageOf3Numbers(int Numbers[3])
{
    return CalculateSumOfNumbers(Numbers) / 3.0;
}

void PrintAverageOf3Numbers(int Numbers[3])
{
    cout << "the average  of Numbers are : " << fixed << setprecision(2) << CalculateAverageOf3Numbers(Numbers);
}

int main()
{

    // #6 :
    PrintFullName(GetFullName(ReadUserInfo()));

    // #7 :
    PrintHalfOfNumber(CalculateHalfOfNumber(GetNumber()));

    // #8 :
    PrintStudentResult(GetMark());

    // #9 :
    int Numbers[3] = {0, 0, 0};
    ReadNumbers(Numbers);
    PrintSumOfThereNumbers(Numbers);

    // #10 :
    ReadNumbers(Numbers);
    PrintAverageOf3Numbers(Numbers);
    return 0;
}