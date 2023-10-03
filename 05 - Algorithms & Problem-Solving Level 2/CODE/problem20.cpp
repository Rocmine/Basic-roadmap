#include <iostream>
#include <ctime>
using namespace std;
struct stSymbolRange
{
    unsigned short From;
    unsigned short To;
    void setSymbolRange(unsigned short From, unsigned short To)
    {

        this->From = From;
        this->To = To;
    }
};

enum enSymbol
{
    Small = 1,
    Capital,
    Special,
    digit
};

stSymbolRange SmallLetter, CapitalLetter, SpecialLetter, digitNumber;

void setSymbolRanges(stSymbolRange &SmallLetter, stSymbolRange &CapitalLetter, stSymbolRange &SpecialLetter, stSymbolRange &digitNumber)
{

    SmallLetter.setSymbolRange(97, 122);
    CapitalLetter.setSymbolRange(65, 90);
    SpecialLetter.setSymbolRange(0, 47);
    digitNumber.setSymbolRange(0, 9);
}

enSymbol getSymbol()
{
    int Number = 0;

    do
    {
        cout << "Enter a Number :";
        cin >> Number;

    } while (Number > enSymbol::digit || Number < enSymbol::Small);

    return enSymbol(Number);
}

int GetRandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}

void Print3RandomSymbol()
{

    cout << "1-Small Letter   :    " << char(GetRandomNumber(SmallLetter.From, SmallLetter.To)) << "\n";
    cout << "2-Capital Letter :    " << char(GetRandomNumber(CapitalLetter.From, CapitalLetter.To)) << "\n";
    cout << "3-Special Letter :    " << char(GetRandomNumber(SpecialLetter.From, SpecialLetter.To)) << "\n\n";
    cout << "4-Digit          :    " << GetRandomNumber(digitNumber.From, digitNumber.To) << "\n\n------------------\n\n";
}

void PrintSpecialSymbol(enSymbol UserSymbol)
{

    if (UserSymbol == enSymbol::Small)
        cout << char(GetRandomNumber(SmallLetter.From, SmallLetter.To)) << "\n";
    if (UserSymbol == enSymbol::Capital)
        cout << char(GetRandomNumber(CapitalLetter.From, CapitalLetter.To)) << "\n";
    if (UserSymbol == enSymbol::Special)
        cout << char(GetRandomNumber(SpecialLetter.From, SpecialLetter.To)) << "\n";
    if (UserSymbol == enSymbol::digit)
        cout << GetRandomNumber(digitNumber.From, digitNumber.To) << "\n";
}
int main()
{
    setSymbolRanges(SmallLetter, CapitalLetter, SpecialLetter, digitNumber);

    srand(time(0));
    Print3RandomSymbol();
    PrintSpecialSymbol(getSymbol());

    return 0;
}