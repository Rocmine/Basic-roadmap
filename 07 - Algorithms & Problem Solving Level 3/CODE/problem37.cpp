/*
problem 37:
write a program to read a string   then make a function to split each word in vector :
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// method 1 :
vector<string> getSplitStringWordToVector(string str, string delim = " ")
{
    vector<string> vstr;
    short counter = 0;
    short pos = 0;
    string word;

    while ((pos = str.find(delim)) != string::npos)
    {

        vstr.push_back(str.substr(0, pos));

        str.erase(0, pos + delim.length());
    }

    // counts the last word :
    if (str != "")
        vstr.push_back(str);

    return vstr;
}

// method 2 :
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

void printVector(const vector<string> &vStr)
{

    for (int i = 0; i < vStr.size(); i++)
    {

        cout << vStr[i] << "\n";
    }
}
int main()
{

    vector<string> vStr;
    string str = input::readString("enter your string :");
    vStr = getSplitStringWordToVector(str);

    cout << "Tokens : " << vStr.size() << "\n";
    printVector(vStr);
}