/*
problem 5: 

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

int getMonthDaysInYear(int year, int month)
{

    if (month == 2)
    {

        return checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28;
    }
    else
    {

        if (month <= 7)
        {
         if (month % 2 != 0)  return 31;
            return 30;
        }
        else
        {

            if (month % 2 == 0) return 31;
            return 30;
        }
    }
}
int daysToHours(int days)
{
    return days * 24;
}
int daysToMinutes(int days)
{
    return daysToHours(days) * 60;
}
int daysToSeconds(int days)
{
    return daysToMinutes(days) * 60;
}

void printYearInfo(int year, int month)
{

    int days = getMonthDaysInYear(year, month);

    cout << "number of days in Month : [" << month << "]"
         << " is " << days << "\n";

    cout << "number of Hours in Month : [" << month << "]"
         << " is " << daysToHours(days) << "\n";

    cout << "number of Minutes in Month : [" << month << "]"
         << " is " << daysToMinutes(days) << "\n";

    cout << "number of Seconds in Month : [" << month << "]"
         << " is " << daysToSeconds(days) << "\n";
}

int main()
{

    int year = input::readIntegerNumber("enter   a year to check  : ");
    int month = input::readIntegerInRange(1, 12, "enter  a Month to check  : ");

    printYearInfo(year, month);

    return 0;
}
