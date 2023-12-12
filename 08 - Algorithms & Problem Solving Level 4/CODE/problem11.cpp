/*
problem 11:
write a program to print total days 
from the beginning of year, then 

take the total days and convert them back to date 

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

int getNbrDaysFromDate(short day, short month, int year)
{

    short days = 0;
    for (int i = 1; i < month; i++)
    {

        days += getMonthDaysInYear(year, i);
    }

    days += day;

    return days;
}

struct stDate
{
    short year;
    short month;
    short day;
};

stDate daysToDate(short remainingDays, short year)
{
    stDate date;
    date.month = 1;
    date.year = year;
    while (true)
    {

        short monthDays = getMonthDaysInYear(year, date.month);

        if (remainingDays > monthDays)
        {
            remainingDays -= monthDays;
            date.month++;
        }
        else
        {
            date.day = remainingDays;
            break;
        }
    }

    return date;
}
int main()
{

    try
    {
        short day = input::readIntegerInRange(1, 30, "enter  a day   :  ");
        short month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
        int year = input::readIntegerNumber("\nenter a Year      :  ");
        int nbrOfDays = getNbrDaysFromDate(day, month, year);
        cout << "Number of Days from the beginning of the year is : " << nbrOfDays << endl;

        stDate date = daysToDate(nbrOfDays, year);
        string strDate = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
        cout << "Date for [" << nbrOfDays << "]"
             << " is : " << strDate << endl;
    }
    catch (runtime_error &e)
    {

        cerr << "Exception : " << e.what() << endl;
    }

    return 0;
}
