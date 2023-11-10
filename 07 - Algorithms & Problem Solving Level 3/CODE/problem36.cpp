/*
problem 36:
write a program to read a string  then count each word in that string :
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;


//method 1 : 
int countEachWordInString(string str)
{
    int wordCounter = 0;
    for (int i = 0; i < str.length() - 1; i++)
    {

        if ((i == 0 && str[i] != ' ') || (str[i] == ' ' && str[i + 1] != ' '))
            wordCounter++;
    }
    return wordCounter;
}

//method 2 : 
int countWord(string str)
{
    string delim = " ";
    short counter = 0;
    short pos = 0;
    string word;

    while ( (pos = str.find(delim) ) != string::npos )
    {

        word = str.substr(0, pos);
        if (word != "") counter++;

        str.erase(0, pos + delim.length());
    }

    // counts the last word :
    if (str != "")
        counter++;

    return counter;
}

int main()
{

    string str = input::readString("enter your string :");

    cout << "\nthe  number of words in your string is : " << countEachWordInString(str);
    cout << "\nthe  number of words in your string is : " << countWord(str);
}