/*
problem 33 to 46:
Write a program to read a date and make a functions
to decrease date as follows:
. decreaseDateByXDays
· decreaseDateByOneWeek
. decreaseDateByXWeeks
. decreaseDateByOneMonth
. decreaseDateByXMonths
. decreaseDateByOneYear
. decreaseDateByXYears
. decreaseDateByXYearsFaster
. decreaseDateByOneDecade
. decreaseDateByXDecades
. decreaseDateByXDecadesFaster
. decreaseDateByOneCentury
. decreaseDateByOneMillennium

*/

#include <iostream>
#include <string>
#include <cmath>
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

bool checkIfValidDay(stDate date)
{

    return date.day <= getMonthDaysInYear(date.year, date.month);
}
stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");
    if (!checkIfValidDay(date))
        date.day = getMonthDaysInYear(date.year, date.month);
    return date;
}

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

void decreaseDateByOneDay(stDate &date)
{

    if (date.day == 1)
    {

        if (date.month == 1)
        {
            date.year--;
            date.day = 31;
            date.month = 12;
        }
        else
        {
            date.month--;
            date.day = getMonthDaysInYear(date.year, date.month);
        }
    }
    else
    {

        date.day--;
    }
}

void decreaseDaysByXDays(stDate &date, int nbrDays)
{

    for (int i = 0; i < nbrDays; i++)
    {

        decreaseDateByOneDay(date);
    }
}
void decreaseDaysByOneWeek(stDate &date)
{

    decreaseDaysByXDays(date, 7);
}

void decreaseDaysByXWeeks(stDate &date, int nbrWeeks)
{
    for (int i = 0; i < nbrWeeks; i++)
    {
        decreaseDaysByOneWeek(date);
    }
}

void decreaseDaysByOneMonth(stDate &date)
{

    if (date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else
    {
        date.month--;
    }

    int nbrDaysInMonth = getMonthDaysInYear(date.year, date.month);
    if (date.day > nbrDaysInMonth)
        date.day = nbrDaysInMonth;
}

void decreaseDaysByXMonths(stDate &date, int nbrMonths)
{

    for (int i = 0; i < nbrMonths; i++)
    {

        decreaseDaysByOneMonth(date);
    }
}

void decreaseDaysByOneYear(stDate &date)
{

    date.year--;
}

void decreaseDaysByXYears(stDate &date, int nbrYears)
{

    for (int i = 0; i < nbrYears; i++)
    {

        decreaseDaysByOneYear(date);
    }
}

void decreaseDaysByOneDecade(stDate &date)
{

    decreaseDaysByXYears(date, 10);
}

void decreaseDaysByXDecades(stDate &date, int nbrDecades)
{

    for (int i = 0; i < nbrDecades; i++)
    {

        decreaseDaysByOneDecade(date);
    }
}
void decreaseDaysByOneCentury(stDate &date)
{

    decreaseDaysByXDecades(date, 10);
}

void decreaseDaysByXCentury(stDate &date, int nbrCentury)
{

    for (int i = 0; i < nbrCentury; i++)
    {
        decreaseDaysByOneCentury(date);
    }
}

void decreaseDaysByOneMillennium(stDate &date)
{

    decreaseDaysByXCentury(date, 10);
}

int main()
{

    stDate date = readDate();

    decreaseDateByOneDay(date);
    cout << "\n1- subtracting one day is      : " << convertDateToString(date) << "\n ";

    decreaseDaysByXDays(date, 10);
    cout << "2- subtracting 10  day is      : " << convertDateToString(date) << "\n ";

    decreaseDaysByOneWeek(date);
    cout << "3- subtracting one week is     : " << convertDateToString(date) << "\n ";

    decreaseDaysByXWeeks(date, 10);
    cout << "4- subtracting 10 weeks is     : " << convertDateToString(date) << "\n ";

    decreaseDaysByOneMonth(date);
    cout << "5- subtracting One Month is    : " << convertDateToString(date) << "\n ";

    decreaseDaysByXMonths(date, 5);
    cout << "6- subtracting 5 Months  is    : " << convertDateToString(date) << "\n ";

    decreaseDaysByOneYear(date);
    cout << "7- subtracting one year is     : " << convertDateToString(date) << "\n ";

    decreaseDaysByXYears(date, 10);
    cout << "8- subtracting 10 years  is    : " << convertDateToString(date) << "\n ";

    decreaseDaysByOneDecade(date);
    cout << "9- subtracting one Decade is   : " << convertDateToString(date) << "\n ";

    decreaseDaysByXDecades(date, 10);
    cout << "10- subtracting 10 Decades is  : " << convertDateToString(date) << "\n ";

    decreaseDaysByOneCentury(date);
    cout << "11- subtracting one Century is : " << convertDateToString(date) << "\n ";

    decreaseDaysByOneMillennium(date);
    cout << "12- subtracting one Millennium is : " << convertDateToString(date) << "\n ";

    return 0;
}