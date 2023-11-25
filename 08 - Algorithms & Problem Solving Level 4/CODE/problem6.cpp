/*
problem 6
write a program to print number of :
days
hours
minutes
seconds

optimized getMonthDaysInYear()
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
    int numberOfDays[12] = {31, month == 2 && checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month - 1];
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

    int year = input::readIntegerNumber("enter a year to check  : ");
    int month = input::readIntegerInRange(1, 12, "enter  a Month to check  : ");

    printYearInfo(year, month);

    return 0;
}
