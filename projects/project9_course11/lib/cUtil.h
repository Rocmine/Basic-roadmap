#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;

class cSymbolRange;
class cUtile
{

    static cSymbolRange SmallLetter, CapitalLetter, SpecialLetter, digitNumber;

public:
    enum enSymbol
    {
        Small = 1,
        Capital,
        Special,
        digit
    };
    static void enCrypt(string &UserText, const int &enCryptCode = 1)
    {

        for (int i = 0; i < UserText.length(); i++)
        {
            UserText[i] += enCryptCode;
        }
    }
    static string enCrypt(string UserText, const int &enCryptCode = 1)
    {

        for (int i = 0; i < UserText.length(); i++)
        {
            UserText[i] += enCryptCode;
        }
        return UserText;
    }
    static void DecCrypt(string &UserText, const int &enCryptCode = 1)
    {

        for (int i = 0; i < UserText.length(); i++)
        {
            UserText[i] -= enCryptCode;
        }
    }

    static string DecCrypt(string UserText, const int &enCryptCode = 1)
    {

        for (int i = 0; i < UserText.length(); i++)
        {
            UserText[i] -= enCryptCode;
        }
        return UserText;
    }

    static void Srand()
    {
        srand(time(0));
    }
    static int GetRandomNumber(int From, int To)
    {

        return rand() % (To - From + 1) + From;
    }

    static void Print3RandomSymbol();
    static void PrintSpecialSymbol(enSymbol UserSymbol);

    static char GetSpecialSymbol(enSymbol UserSymbol);

    static string getkey(enSymbol UserSymbol = Small)
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

    static void GenerateNKey(unsigned short KeyNumbers = 10, enSymbol UserSymbol = Small)
    {

        for (int i = 1; i <= KeyNumbers; i++)
        {

            cout << "key[" << i << "] : " << getkey(UserSymbol) << "\n";
        }
        cout << endl;
    }
    static vector<string> GetVectorWittNKey(unsigned short KeyNumbers = 10, enSymbol UserSymbol = Small)
    {
        vector<string> result;
        for (int i = 1; i <= KeyNumbers; i++)
        {

            result.push_back(getkey(UserSymbol));
        }
        return result;
    }

    static vector<int> GetVectorWithRandomValues(int Length, int min = 0, int max = 100)
    {

        vector<int> vArr;

        for (unsigned i = 0; i < Length; i++)
        {
            vArr.push_back(GetRandomNumber(0, 100));
        }
        return vArr;
    }
    template <typename T>
    static void printPrimitiveVector(const vector<T> &vArr, string text = "the value ")
    {
        for (const T &element : vArr)
        {

            cout << text << " " << element << endl;
        }
    }
    template <typename T>
    static T getSumVector(const vector<T> &vArr)
    {
        T Sum = 0;
        for (unsigned i = 0; i < vArr.size(); i++)
            Sum += vArr[i];

        return Sum;
    }
    template <typename T>
    static auto getAverageVector(const vector<T> &vArr)
    {
        return float(getSumVector(vArr)) / vArr.size();
    }

    template <typename T>
    static T GetMaxInAVector(const vector<T> &vArr)
    {
        T Max = vArr[0];
        for (unsigned i = 0; i < vArr.size(); i++)
        {
            if (vArr[i] > Max)
                Max = vArr[i];
        }
        return Max;
    }
    template <typename T>
    static T GetMinInAVector(const vector<T> &vArr)
    {
        T Min = vArr[0];
        for (unsigned i = 0; i < vArr.size(); i++)
        {
            if (vArr[i] < Min)
                Min = vArr[i];
        }
        return Min;
    }
    template <typename T>
    static void Swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    template <typename T>
    static void ShuffleVector(vector<T> &v)
    {

        for (unsigned i = 0; i < v.size(); i++)
        {

            unsigned RandomIndex1 = GetRandomNumber(0, v.size() - 1);
            unsigned RandomIndex2 = GetRandomNumber(0, v.size() - 1);
            Swap(v[RandomIndex1], v[RandomIndex2]);
        }
    }
};

class cSymbolRange
{
private:
    int From;
    int To;

public:
    cSymbolRange(int From, int To) : From(From), To(To) {}

    // Declare Print3RandomSymbol() and PrintSpecialSymbol() as friend functions
    friend void cUtile::Print3RandomSymbol();
    friend void cUtile::PrintSpecialSymbol(cUtile::enSymbol UserSymbol);
    friend char cUtile::GetSpecialSymbol(enSymbol UserSymbol);
};
cSymbolRange cUtile::SmallLetter(97, 122);
cSymbolRange cUtile::CapitalLetter(65, 90);
cSymbolRange cUtile::SpecialLetter(0, 47);
cSymbolRange cUtile::digitNumber(0, 9);

void cUtile::PrintSpecialSymbol(enSymbol UserSymbol = enSymbol::Small)
{

    if (UserSymbol == Small)
        cout << char(GetRandomNumber(SmallLetter.From, SmallLetter.To)) << "\n";
    if (UserSymbol == Capital)
        cout << char(GetRandomNumber(CapitalLetter.From, CapitalLetter.To)) << "\n";
    if (UserSymbol == Special)
        cout << char(GetRandomNumber(SpecialLetter.From, SpecialLetter.To)) << "\n";
    if (UserSymbol == digit)
        cout << GetRandomNumber(digitNumber.From, digitNumber.To) << "\n";
}

void cUtile::Print3RandomSymbol()
{

    cout << "1-Small Letter   :    " << char(GetRandomNumber(SmallLetter.From, SmallLetter.To)) << "\n";
    cout << "2-Capital Letter :    " << char(GetRandomNumber(CapitalLetter.From, CapitalLetter.To)) << "\n";
    cout << "3-Special Letter :    " << char(GetRandomNumber(SpecialLetter.From, SpecialLetter.To)) << "\n\n";
    cout << "4-Digit          :    " << GetRandomNumber(digitNumber.From, digitNumber.To) << "\n\n------------------\n\n";
}

char cUtile::GetSpecialSymbol(enSymbol UserSymbol)
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

template <typename T>
vector<T> operator+(vector<T> v1, vector<T> v2)
{
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{

    for (int i = 0; i < v.size(); i++)
    {

        cout << "V[" << i << "] = " << v[i] << "\n";
    }
    return out;
}