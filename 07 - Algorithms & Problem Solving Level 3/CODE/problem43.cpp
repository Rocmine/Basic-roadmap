/*
problem 43:
write a program to replace words in string using custom function  :
(with  math case or without math case )
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;
string toUpperString(string str)
{

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}
enum enMatchCase
{
    no,
    yes
};

void ReplaceWord(enMatchCase matchCase, string &word, string oldWord, string newWord)
{
    if (matchCase == enMatchCase::yes && word == oldWord)
        word = newWord;
    if (matchCase == enMatchCase::no && toUpperString(word) == toUpperString(oldWord))
        word = newWord;
}

string replaceWordInString(string str, string oldWord, string newWord, enMatchCase matchCase = enMatchCase::yes)
{

    string word = "";
    string resultStr;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] != ' ')
            word += str[i];

        if (((i != str.length() - 1) && (str[i] != ' ' && str[i + 1] == ' ' && word != "")) || (i == str.length() - 1 && str[str.length() - 1] != ' '))
        {

            ReplaceWord(matchCase, word, oldWord, newWord);
            resultStr += word + " ";
            word = "";
        }
    }
    return resultStr;
}

int main()
{

    string str = "Welcome to Jordan , Jordan is a nice country";
    cout << "Original string \n";
    cout << str << "\n";

    cout << "\nreplace with math case :  \n";
    cout << replaceWordInString(str, "jordan", "Morocco") << "\n"
         << endl;

    cout << "\nreplace without math case :  \n";
    cout << replaceWordInString(str, "jordan", "Morocco", enMatchCase::no) << "\n"
         << endl;
}