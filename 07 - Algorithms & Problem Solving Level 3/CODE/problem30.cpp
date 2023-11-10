/*
problem 30:
write a program to read a string and read a character then count the character in that string :
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

int getNumberOfFrequencyOfLetterInString(string str, char letter)
{

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == letter)
            count++;
    }

    return count;
}

int main()
{
    string str = input::readString("enter your string :");
    cout << "String length :" << str.length() << "\n";
    char letter = input::readCharacter("enter a character ");

    cout << "letter " << letter << " count = " << getNumberOfFrequencyOfLetterInString(str, letter) << endl;

    return 0;
}