/*
problem 26 :
write a program to read a string then  upper all letters , then lower all letters  an print them  :
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

void toLowerString(string &str)
{

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
}
void toUpperString(string &str)
{

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

int main()
{

    string str = input::readString("enter your string :");
    cout << "\nstring after upper :";
    toUpperString(str);
    cout << "\n" << str << endl;

    cout << "\nstring after lower : \n";
    toLowerString(str);
    cout << str << endl;

    return 0;
}