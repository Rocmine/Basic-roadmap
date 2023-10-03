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
        {
            Key[i] = GetSpecialSymbol(UserSymbol);
        }
    }

    return Key;
}

int ReadNumberInRange(string UserText, const int Max, const int Sum)
{
    int num = 0;
    do
    {
        cout << UserText;
        cin >> num;

    } while (Max > num || Sum < num);

    return num;
}

void SetArrayRandomKeyValues(string Array[50], unsigned &Length)
{
    Length = ReadNumberInRange("Enter the length :", 0, 100);
    for (unsigned i = 0; i < Length; i++)
    {
        Array[i] = getkey(enSymbol::Capital);
    }
}

void PrintArrayValues(const string TextToShow, string Array[], const unsigned Length)
{
    cout << TextToShow << "\n";
    for (unsigned i = 0; i < Length; i++)
    {
        cout << "Array[" << i << "] : " << Array[i] << "\n";
    }
    cout << endl;
}

int main()
{

    setSymbolRanges(SmallLetter, CapitalLetter, SpecialLetter, digitNumber);
    srand(time(NULL));
    string keysArray[50];
    unsigned Length = 0;
    SetArrayRandomKeyValues(keysArray, Length);
    PrintArrayValues("Array Elements :", keysArray, Length);
}