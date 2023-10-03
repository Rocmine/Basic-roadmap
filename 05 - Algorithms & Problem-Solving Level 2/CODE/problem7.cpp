

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

unsigned GetReverseNumber(unsigned Number)
{
    unsigned ReversedNumber = 0;
    while (Number != 0)
    {
        ReversedNumber = ReversedNumber * 10 + Number % 10;
        Number /= 10;
    }
    return ReversedNumber;
}
void PrintReversedNumber(const unsigned ReversedNumber)
{
    cout << "the  Reverse is :   : " << ReversedNumber << endl;
}
int main()
{

    PrintReversedNumber(GetReverseNumber(ReadPositiveNumber("Enter a Number : ")));
    return 0;
}