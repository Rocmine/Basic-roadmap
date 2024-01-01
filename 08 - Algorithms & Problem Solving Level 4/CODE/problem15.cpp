/*
problem 15:
Write a program to read date and check :
if it last day in month
if it is last month in year :

*/
#include <iostream>
#include <string>
#include "myLib.h"
#include <iomanip>
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

short getMonthDaysInYear(short year, short month)
{
    int numberOfDays[] = {0, 31, checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month];
}

struct stDate
{
    short year;
    short month;
    short day;
};

bool checkIfLastDaysInMonth(stDate date)
{

    return date.day == getMonthDaysInYear(date.year, date.month);
}

bool checkIfLastMonthInYear(short month)
{

    return month == 12;
}

stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");

    return date;
}

int main()
{
    stDate date = readDate();
    cout << endl;
    if (checkIfLastDaysInMonth(date))
    {
        cout << " Yes, Day is Last Day in Month\n";
    }
    if (checkIfLastMonthInYear(date.month))
    {
        cout << "Yes, Month is Last Month in Year\n";
    }

    return 0;
}