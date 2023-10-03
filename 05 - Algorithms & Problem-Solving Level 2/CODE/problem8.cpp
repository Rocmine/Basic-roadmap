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

void PrintResult(string Text, unsigned Result)
{

    cout << Text << Result << endl;
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

int main()
{

    unsigned Number = ReadPositiveNumber("Enter a Number : ");
    unsigned short Digit = ReadPositiveNumber("Enter a Digit : ");
    PrintResult("The Number of Frequency is :  ", GetDigitFrequency(Number, Digit));
    return 0;
}