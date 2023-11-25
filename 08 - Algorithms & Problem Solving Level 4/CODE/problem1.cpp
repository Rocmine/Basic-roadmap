/*
 problem 1 :
 write a program to read a number and print the text of that number
*/
#include <iostream>
#include <string>
#include"myLib.h"
using namespace std; 

std::string convertFromNumberToText(long long number)
{
    if (number == 0)
        return "";

    if (number >= 1 && number <= 19)
    {
        std::string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

        return arr[number];
    }

    if (number >= 20 && number <= 99)
    {
        std::string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        return arr[number / 10] + " " + convertFromNumberToText(number % 10);
    }

    if (number >= 100 && number <= 999)
    {
        std::string arr[] = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};

        return convertFromNumberToText(number / 100) + " Hundred " + convertFromNumberToText(number % 100);
    }

    if (number >= 1000 && number <= 999999)
    {
        return convertFromNumberToText(number / 1000) + " Thousand " + convertFromNumberToText(number % 1000);
    }

    if (number >= 1000000 && number <= 999999999)
    {

        return convertFromNumberToText(number / 1000000) + " Million " + convertFromNumberToText(number % 1000000);
    }

    if (number >= 1000000000 && number <= 999999999999)
    {

        return convertFromNumberToText(number / 1000000000) + " Billion " + convertFromNumberToText(number % 1000000000);
    }
     if (number >= 1000000000000 && number <= 999999999999999)
    {

        return convertFromNumberToText(number / 1000000000000) + " Trillion " + convertFromNumberToText(number % 1000000000000);
    }

    return "";
}

int main()
{
    long long number=input::readIntegerNumber("enter the number : ");
  

    string result = convertFromNumberToText(number);
    cout << result <<endl;

    return 0;
}
