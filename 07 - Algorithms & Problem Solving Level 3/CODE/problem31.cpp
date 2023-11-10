/*
problem 31:
write a program to read a string and read a character then count the character in that string (math case or not ):
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

int getFrequencyOfLetterWithMatchingCase(string str, char letter)
{

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == letter)
            count++;
    }

    return count;
}
char invertCase(char character)
{

    if (isupper(character))
        return tolower(character);
    else
        return toupper(character);
}

int getFrequencyOfLetterWithoutMatchingCase(string str, char letter)
{

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (toupper(str[i]) == toupper(letter))
            count++;
    }

    return count;
}
int main()
{
    string str = input::readString("enter your string :");
    cout << "String length :" << str.length() << "\n";
    char letter = input::readCharacter("enter a character ");

    cout << "letter " << letter << " count = " << getFrequencyOfLetterWithMatchingCase(str, letter) << endl;
    cout << "letter " << invertCase(letter) << " or " << letter << " count = " << getFrequencyOfLetterWithoutMatchingCase(str, letter) << endl;

    return 0;
}