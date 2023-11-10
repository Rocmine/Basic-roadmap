/*
problem 35:
write a program to read a string  then print each word in that string 
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;



void countEachWordInString(string str)
{

cout<<endl; 
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i]==' ')cout <<"\n";
        else cout<<str[i]; 

    }
}

int main()
{

    string str = input::readString("enter your string :");

    cout << "\n vowels in string are : ";
    countEachWordInString(str);
}