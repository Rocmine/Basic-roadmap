/*
problem 33:
write a program to read a string  then count all vowels in that string 
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

int countVowels(string str)
{

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (checkIfLetterIsVowel(str[i]) == enIsVowel::yes)
            count++;
    }

    return count;
}

int main()
{

    string str = input::readString("enter your string :");

    cout << "\nNumber of vowels is: " << countVowels(str) << endl;
}