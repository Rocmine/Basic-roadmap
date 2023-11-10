/*
problem 29 :
write a program to read a string then count small/capital letters in that sting 
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

int getNumberOfCapitaLetterInString(string str)
{

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (isupper(str[i]))
            count++;
    }

    return count;
}

int getNumberOfSmallLetterInString(string str)
{

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (islower(str[i]))
            count++;
    }

    return count;
}

int main()
{
    string str = input::readString("enter your string :");
    cout << "String length :" << str.length() << "\n";

    cout << "capital letters count=" << getNumberOfCapitaLetterInString(str) << "\n";
    cout << "capital letters count=" << getNumberOfSmallLetterInString(str) << "\n";

    return 0;
}