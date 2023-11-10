/*
problem 44:
write a program to remove all punctuations from a string : 

*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void shiftLeft(int shiftIndex, string &str)
{

    for (int i = shiftIndex; i < str.length() - 1; i++)
    {

        str[i] = str[i + 1];
    }
    str.resize(str.length() - 1);
}

string RemovePunctuationsFromsString(string str)
{

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ',')
        {
            shiftLeft(i, str);
            i--;
        }
    }
    return str;
}

int main()
{

    string str = "Welcome to Jordan , Jordan is a nice country";
    cout << "Original string \n";
    cout << str << "\n";

    cout << "\n Punctuations Removed   \n";
    cout << RemovePunctuationsFromsString(str) << "\n"
         << endl;
    return 0;
}