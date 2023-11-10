/*
problem 23 :
write a program to read a string then print the first letter of each word in that string :
*/

#include <iostream>
#include "myLib.h"
#include <string>
using namespace std;

void printFirstLetterOfString(string str)
{

    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 || str[i - 1] == ' ')  cout << str[i] << "\n";
    }
}

int main()
{

    string str = input::readString("enter your string :");
    cout << "First letters of this  string : \n";
  printFirstLetterOfString(str); 
    return 0;
}