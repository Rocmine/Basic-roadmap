#include <iostream>
using namespace std;

// #26 print Number to N :
int GetNumber()
{
    int Number = 0;
    cout << "enter a Number :";
    cin >> Number;
    return Number;
}

void PrintNumberToN(int N)
{

    for (int i = 1; i <= N; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

// #26 print Number From N To 1 :
void PrintNumberFromNTo1(int N)
{

    for (int i = N; i >= 1; i--)
    {
        cout << i << " ";
    }
    cout << endl;
}

// #27 Sum Numbers From N To 1 :

int SumNumbersFrom1ToN(int N)
{
    int Sum = 0;
    for (int i = 1; i <= N; i++)
    {
        Sum += i;
    }
    return Sum;
}

void PrintResult(int Result)
{

    cout << "The Result is : " << Result << endl;
}

enum enOddOrEven
{
    Even,
    Odd
};
// #28 Sum Even Numbers From N To 1 :

enOddOrEven CheckOddOrEven(int Number)
{

    return Number % 2 == 0 ? enOddOrEven::Even : enOddOrEven::Odd;
}

int SumEvenNumbersFrom1ToN(int N)
{
    int Sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (CheckOddOrEven(i))
            Sum += i;
    }
    return Sum;
}

// #30 Factorial   :
int SumOddNumbersFrom1ToN(int N)
{
    int Sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!CheckOddOrEven(i))
            Sum += i;
    }
    return Sum;
}

int ReadPositiveNumber()
{

    int N = 0;
    do
    {
        N = GetNumber();
    } while (N < 0);
}
long double CalculateFactorial(int N)
{

    long double Fact = 1;
    for (int i = 2; i <= N; i++)
    {
        Fact *= i;
    }
    return Fact;
}
void PrintFactorial(long double Fact)
{
    cout << "the Factorial is :" << Fact << endl;
}

int main()
{

    // #25
    PrintNumberToN(GetNumber());

    // #26
    PrintNumberFromNTo1(GetNumber());

    // #27 :
    PrintResult(SumNumbersFrom1ToN(GetNumber()));

    // #28:
    PrintResult(SumEvenNumbersFrom1ToN(GetNumber()));
    // #29:
    PrintResult(SumOddNumbersFrom1ToN(GetNumber()));
    // #30 :
    PrintFactorial(CalculateFactorial(ReadPositiveNumber()));
}