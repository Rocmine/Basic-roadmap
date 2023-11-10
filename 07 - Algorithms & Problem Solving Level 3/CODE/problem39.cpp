/*
problem 40:
write a program to join (array or vector ) of strings ino a one string separators :

*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

string joinString(vector<string> &vStr, string delim = " ")
{

    string resultStr = "";
    for (string &element : vStr)
    {

        resultStr += element + delim;
    }

    return resultStr.substr(0, resultStr.length() - delim.length());
}

string joinString(string arrStr[], int length, string delim = " ")
{

    string resultStr = "";

    for (int i = 0; i < length; i++)
    {

        resultStr += arrStr[i] + delim;
    }

    return resultStr.substr(0, resultStr.length() - delim.length());
}

int main()
{

    vector<string> vStr = {"ayoub", "adam", "amine"};
    string arrStr[3] = {"ayoub", "adam", "amine"};

    cout << "\nVector after join :\n";
    cout << joinString(vStr, "#") << endl;

    int length = sizeof(arrStr) / sizeof(arrStr[0]);
    cout << "\nArray after join :\n";
    cout << joinString(arrStr, length, "#") << endl
         << endl;
}