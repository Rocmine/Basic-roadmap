/*
problem 27 :
write a program  to read a character then invert it's case and print it :
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

int main()
{

    char character = input::readCharacter("enter a character :");

    cout << character << endl;

    cout << "char after inverting  case :\n";
    cout << invertCase(character);
}