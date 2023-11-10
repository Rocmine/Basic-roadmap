/*
problem 42:
write a program to replace words in string  :

*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;
string replaceWordInString(string str, string oldWord, string newWord)
{

    string word = "";
    string resultStr;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] != ' ')
            word += str[i];

        if (((i != str.length() - 1) && (str[i] != ' ' && str[i + 1] == ' ' && word != "")) || (i == str.length() - 1 && str[str.length() - 1] != ' '))
        {
            if (word == oldWord)
                word = newWord;
            resultStr += word +" ";
            word = "";
        }
    }
    return resultStr;
}

int main()
{

    string str = "Welcome to Jordan , Jordan is a nice country";
    cout<<"Original string \n";
    cout<<str<<"\n"; 

    cout << "\nString after reversing words \n";
    cout << replaceWordInString(str, "Jordan", "Morocco") <<"\n"<< endl;
}