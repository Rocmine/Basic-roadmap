/*
problem 38:
write a program to read a string   then trim left , right ,all
trim  =>  remove spaces
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

        if (str[i] != ' ')
            return str;

        if (str[i] == ' ')
        {
            shiftLeft(i, str);
            i--;
        }
    }
}

string trimRight(string str)
{

    for (int i = str.length() - 1; i >= 0; i--)
    {

        if (str[i] != ' ')   return str;
        

        if (str[i] == ' ')   str.resize(str.length() - 1);
        
    }
}

string trim(string str)
{

    str = RemovePunctuationsFromsString(str);
    str = trimRight(str);
    return str;
}

int main()
{

    vector<string> vStr;
    string str = "    ayoub majid     ";
    cout << "string =" <<str<< endl;
    cout << "Trim left       =" << RemovePunctuationsFromsString(str) << "\n";
    cout << "Trim Right      =" << trimRight(str) << "\n";
    cout << "Trim            =" << trim(str) << endl;
}