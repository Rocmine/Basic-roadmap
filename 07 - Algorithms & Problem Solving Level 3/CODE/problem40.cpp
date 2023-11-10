/*
problem 41:
write a program to read string  and reverse its words  :

*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;
vector<string> getSplitStringWordToVector2(string str)
{

    vector<string> vStr;
    string word = "";
    int wordCounter = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] != ' ')
            word += str[i];

        if (((i != str.length() - 1) && (str[i] != ' ' && str[i + 1] == ' ' && word != "")) || (i == str.length() - 1 && str[str.length() - 1] != ' '))
        {
            vStr.push_back(word);
            word = "";
        }
    }
    return vStr;
}

string getReverseString(string str)
{

    vector<string> vStr = getSplitStringWordToVector2(str);

    string resultStr = "";
    for (int i = vStr.size() - 1; i >= 0; i--)
    {

        resultStr += vStr[i] + " ";
    }

    return resultStr;
}

int main()
{

    string str = input::readString("enter your string :");

    cout << "String after reversing words \n";
    cout << getReverseString(str) << endl;
}