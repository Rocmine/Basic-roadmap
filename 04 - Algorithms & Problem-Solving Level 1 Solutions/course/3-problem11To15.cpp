#include <iostream>
#include <iomanip>
using namespace std;

// #11  average  of there Marks  with status:
enum enStudentStat
{
    Fail,
    Pass
};

void ReadMarks(int Marks[3])
{
    cout << "Enter There   Marks :";
    for (int i = 0; i < 3; i++)
    {

        cin >> Marks[i];
    }
}

int CalculateSumOfMarks(int Marks[3])
{
    int SumMarks = 0;
    for (int i = 0; i < 3; i++)
    {
        SumMarks += Marks[i];
    }
    return SumMarks;
}
float CalculateAverageOf3Marks(int Marks[3])
{
    return CalculateSumOfMarks(Marks) / 3.0;
}

enStudentStat isAcceptedMark(int AverageMarks)
{
    return AverageMarks >= 50 ? enStudentStat::Pass : enStudentStat::Fail;
}

void PrintStudentResult(float AverageMarks)
{
    cout << "Your Average is :" << fixed << setprecision(2) << AverageMarks << " ";
    isAcceptedMark(AverageMarks) == enStudentStat::Pass ? cout << ""
                                                               << "Pass"
                                                        : cout << "Fail";
}

// # 12 Max of Two Numbers :

void ReadTwoNumbers(int &Num1, int &Num2)
{
    cout << "Enter Two Numbers ";
    cin >> Num1 >> Num2;
}

int GetMaxOf2Numbers(const int Num1, const int Num2)
{
    return Num1 > Num2 ? Num1 : Num2;
}

void PrintMaxOfNumbers(int Max)
{

    cout << "The max is : " << Max << "\n";
}

// # 13 Max of There Numbers :
void ReadNumbers(int Numbers[3])
{
    cout << "Enter There   Numbers :";
    for (int i = 0; i < 3; i++)
    {

        cin >> Numbers[i];
    }
}

int GetMaxOf3Numbers(const int Numbers[3])
{
    int MaxOf2 = GetMaxOf2Numbers(Numbers[0], Numbers[1]);
    return MaxOf2 > Numbers[2] ? MaxOf2 : Numbers[2];
}

// 14 # swap two Numbers :

void Swap(int &Num1, int &Num2)
{
    Num1 += Num2;
    Num2 = Num1 - Num2;
    Num1 -= Num2;
}

void PrintSwap(const int Num1, const int Num2)
{

    cout << "Num1 :" << Num1 << "\n";
    cout << "Num2 :" << Num2 << "\n"
         << endl;
}
 // #15  Rectangle Aria : Relation = width*height  
struct stRectangle
{
    int width;
    int height;
};

stRectangle GetAriaRectangleInfo()
{
    stRectangle Rectangle;
    cout << "Enter the width :";
    cin >> Rectangle.width;
    cout << "Enter the height :";
    cin >> Rectangle.height;
    return Rectangle;
}

int CalculateRectangleAria(stRectangle Rectangle)
{
    return Rectangle.height * Rectangle.width;
}

void PrintAria(int Aria)
{
    cout << "The Aria is : " << Aria << "\n";
}
int main()
{

    // # 11 :
    int Marks[3] = {0, 0, 0};
    ReadMarks(Marks);
    PrintStudentResult(CalculateAverageOf3Marks(Marks));
    // # 12 :
    int Num1 = 0, Num2 = 0;

    ReadTwoNumbers(Num1, Num2);
    PrintMaxOfNumbers(GetMaxOf2Numbers(Num1, Num2));

    // #13 :
    int Numbers[3] = {0, 0, 0};
    ReadNumbers(Numbers);
    ;
    PrintMaxOfNumbers(GetMaxOf3Numbers(Numbers));

    // # 14 :
    ReadTwoNumbers(Num1, Num2);
    PrintSwap(Num1, Num2);
    Swap(Num1, Num2);
    PrintSwap(Num1, Num2);

    // #15 :
    PrintAria(CalculateRectangleAria(GetAriaRectangleInfo()));

    return 0;
}