#include <iostream>
#include <cctype>
#include <string>
using namespace std;

enum enPasswordChecker
{
    NotFount,
    Found
};

string ReadString(string UserText)
{
    string str = "";

    do
    {
        cout << UserText;
        cin >> str;

    } while (str.length() > 3 || (isdigit(str[0]) || isdigit(str[1]) || isdigit(str[2])));

    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}

string GetWord(unsigned Char1, unsigned Char2, unsigned Char3)
{

    string word = {char(Char1), char(Char2), char(Char3)};

    return word;
}
enPasswordChecker PrintResult(string word, string UserPassword, unsigned TrialCounter)
{

    if (word == UserPassword)
    {
        cout << "\n\nPassword is :" << word << "\n";
        cout << "Found After " << TrialCounter << " Trial(s)" << endl;
        return enPasswordChecker::Found;
    }
    else
        return enPasswordChecker::NotFount;
}

void guessPassword(string UserPassword)
{

    string word = "";
    unsigned TrialCounter = 0;
    for (unsigned i = int('A'); i <= int('Z'); i++)
    {
        for (unsigned j = int('A'); j <= int('Z'); j++)
        {
            for (unsigned k = int('A'); k <= int('Z'); k++)
            {
                word = GetWord(i, j, k);
                cout << "Trial[" << TrialCounter++ << "]: " << word << "\n";
                if (PrintResult(word, UserPassword, TrialCounter) == enPasswordChecker::Found)
                    return;
            }
        }
    }
}

int main()
{
    guessPassword(ReadString("Enter a Password : "));

    return 0;
}