/*
problem 28 :
write a program  to read a string then invent all its letter's case and print it :
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

char invertCase(char character)
{

    if (isupper(character))
        return tolower(character);
    else
        return toupper(character);
}

void inventString(string &str)
{

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = invertCase(str[i]);
    }
}
int main()
{

    string str = input::readString("enter your string :");
    cout << "\nstring  inventing all letters case  :";
    inventString(str);
    cout << "\n"  << str << endl;
}