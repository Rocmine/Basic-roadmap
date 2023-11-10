/*
problem 34:
write a program to read a string  then print all vowels in that string
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

enum enIsVowel
{
    no,
    yes
};

enIsVowel checkIfLetterIsVowel(char letter)
{
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') ? enIsVowel::yes : enIsVowel::no;
}

void printVowels(string str)
{

    for (int i = 0; i < str.length(); i++)
    {

        if (checkIfLetterIsVowel(str[i]) == enIsVowel::yes)
            cout << str[i] << "  ";
    }
}

int main()
{

    string str = input::readString("enter your string :");

    cout << "\n vowels in string are : ";
    printVowels(str);
}