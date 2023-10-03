#include <iostream>
using namespace std;

unsigned ReadPositiveNumber(string UserText)
{
    unsigned num = 0;

    do
    {
        cout << UserText;
        cin >> num;
    } while (num <= 0);
    return num;
}

int GetDigitFrequency(unsigned Number, unsigned short Digit)
{

    unsigned counter = 0;
    while (Number != 0)
    {
        if (Number % 10 == Digit)
            counter++;
        Number /= 10;
    }
    return counter;
}

enum enIsAlreadyChecked
{
    NotChecked,
    isChecked
};
enIsAlreadyChecked isAlreadyCheckedDigit(unsigned Number, const unsigned short Digit, unsigned short CounterChecked)
{

    while (CounterChecked)
    {

        if (Number % 10 == Digit)
            return enIsAlreadyChecked::isChecked;
        Number = Number / 10;
        CounterChecked--;
    }
    return enIsAlreadyChecked::NotChecked;
}

void PrintFrequency(enIsAlreadyChecked CheckedStat, const unsigned short Digit, unsigned Number)
{

    if (CheckedStat == enIsAlreadyChecked::NotChecked)
    {

        cout << "The Digit Frequency of " << Digit << " Is : " << GetDigitFrequency(Number, Digit) << "\n";
    }
}

void PrintDigitsFrequency(const  unsigned Number)
{

    unsigned short CounterChecked = 0;
    unsigned TempNumber=Number;  
    while (TempNumber != 0)
    {
        unsigned short Digit = TempNumber % 10;

        PrintFrequency(isAlreadyCheckedDigit(Number, Digit, CounterChecked++), Digit, Number);

        TempNumber /= 10;
    }
}

int main()
{
    PrintDigitsFrequency(ReadPositiveNumber("Enter a Number : "));
    return 0;
}