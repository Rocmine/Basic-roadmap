/*
problem 32:
write a program to read a character then check of it is a vowel or not (vowels : a,e,i,o,i)
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
letter=tolower(letter); 
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') ? enIsVowel::yes : enIsVowel::no;
}



int main()
{

    char letter = input::readCharacter("enter a character ");

    if (checkIfLetterIsVowel(letter) == enIsVowel::yes)
    {

        cout << "Yes letter  '" << letter << "' is vowel \n";
    }
    else
    {
        cout << "No letter  '" << letter << "' is not  vowel \n";
    }
}