/*
problem 24 :
write a program to read a string then uppercase the first letter of each word in that string :
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

void lowercaseTheFirstLetterOfString(string &str)
{

    for (int i = 0; i < str.length(); i++)
    {
        if ((i == 0 || str[i - 1] == ' ')) str[i] = toupper(str[i]);
    }
}

int main()
{

    string str = input::readString("enter your string :");
    cout << "string after conversion : \n";
    lowercaseTheFirstLetterOfString(str);
    cout << str;
    return 0;
}