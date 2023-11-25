/*
problem 4: 

write a program to print number of :
days
hours
minutes
seconds
*/

#include <iostream>
#include <string>
#include "myLib.h"
using namespace std;
enum enIsLeapYear
{
    noLeap,
    isLeap
};

enIsLeapYear checkIfYearIsLeap(int year)
{

    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? enIsLeapYear::isLeap : enIsLeapYear::noLeap;
}

void printYearInfo(int year)
{

    int days = checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 366 : 365;

    cout << "number of days in Year : [" << year << "]"
         << " is " << days << "\n";
    cout << "number of Hours in Year : [" << year << "]"
         << " is " << days * 24 << "\n";
    cout << "number of Minutes in Year : [" << year << "]"
         << " is " << days * 24 * 60 << "\n";
    cout << "number of Seconds in Year : [" << year << "]"
         << " is " << days * 24 * 60 * 60 << "\n";
}

int main()
{

    int year = input::readIntegerNumber("enter the a year : ");
    printYearInfo(year);

    return 0;
}
