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
    SpecialLetter.setSymbolRange(33, 47);
    digitNumber.setSymbolRange(48, 57);
}

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

enSymbol ReadSymbol()
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
char GetSpecialSymbol(enSymbol UserSymbol)
{

    if (UserSymbol == enSymbol::Small)
        return GetRandomNumber(SmallLetter.From, SmallLetter.To);
    if (UserSymbol == enSymbol::Capital)
        return GetRandomNumber(CapitalLetter.From, CapitalLetter.To);
    if (UserSymbol == enSymbol::Special)
        return GetRandomNumber(SpecialLetter.From, SpecialLetter.To);
    if (UserSymbol == enSymbol::digit)
        return GetRandomNumber(digitNumber.From, digitNumber.To);
}
string getkey(enSymbol UserSymbol)
{
    string Key = "                   ";

    for (int i = 0; i < 20; i++)
    {
        if (i == 4 || i == 9 || i == 14)
            Key[i] = '-';
        else
            Key[i] = GetSpecialSymbol(UserSymbol);
    }
    return Key;
}

void GenerateNKey(unsigned short KeyNumber, enSymbol UserSymbol)
{

    for (int i = 1; i <= KeyNumber; i++)
    {

        cout <<"key["<< i << "] : "<< getkey(UserSymbol) << "\n";
    }
    cout << endl;
}
void Print3RandomSymbol()
{

    cout << "1-Small Letter   :    " << GetSpecialSymbol(enSymbol::Small) << "\n";
    cout << "2-Capital Letter :    " << GetSpecialSymbol(enSymbol::Capital) << "\n";
    cout << "3-Special Letter :    " << GetSpecialSymbol(enSymbol::Special) << "\n\n";
    cout << "4-Digit          :    " << GetSpecialSymbol(enSymbol::digit) << "\n\n------------------\n\n";
}
int main()
{
    setSymbolRanges(SmallLetter, CapitalLetter, SpecialLetter, digitNumber);

    srand(time(0));

    unsigned short KeysNumber = ReadPositiveNumber("Enter the Number of keys :");
    Print3RandomSymbol();
    enSymbol UserSymbol = ReadSymbol();
    GenerateNKey(KeysNumber, UserSymbol);

    return 0;
}